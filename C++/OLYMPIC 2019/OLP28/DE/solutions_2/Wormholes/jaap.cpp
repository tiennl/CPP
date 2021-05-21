/* NWERC 2009 solution by Jaap Eldering
 * Problem: Wormholes
 */

#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

#define ALL(x) ((x).begin()),((x).end())
#define REP(i,n) for(int i=0; i<(n); ++i)

const int infty = 999999999;

struct point {
	int x, y, z;
};

int operator <(point a, point b)
{
	if ( a.x!=b.x ) return a.x<b.x;
	if ( a.y!=b.y ) return a.y<b.y;
	return a.z<b.z;
}

int sqr(int x) { return x*x; }
int dist(point a, point b) { return ceil(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z))); }

struct wormhole {
	point start, end;
	int t0, dt;
};

struct edge {
	int fr, to;
	int t0, dt;

	edge() {};
	edge(int _fr, int _to, int _dt, int _t0 = -infty):
		fr(_fr), to(_to), t0(_t0), dt(_dt) {};
};

point dep, arr;
vector<wormhole> wormholes;

int src, dst; // indices of departure and arrival point
vector<edge> edges;

int V;
vector<int> besttime; // First time to arrive (currently best)
vector<int> lastedge; // Last edge used to update besttime

void read_init()
{
	set<point> points;
	int n;
	edges.clear();

	scanf("%d %d %d %d %d %d\n",&dep.x,&dep.y,&dep.z,&arr.x,&arr.y,&arr.z);
	scanf("%d\n",&n);

	points.insert(dep);
	points.insert(arr);

	wormholes.resize(n);
	REP(i,n) {
		scanf("%d %d %d %d %d %d %d %d\n",
		      &wormholes[i].start.x,&wormholes[i].start.y,&wormholes[i].start.z,
		      &wormholes[i].end.x,  &wormholes[i].end.y,  &wormholes[i].end.z,
		      &wormholes[i].t0,&wormholes[i].dt);
		points.insert(wormholes[i].start);
		points.insert(wormholes[i].end);
	}

	src = 2*n;
	dst = 2*n+1;
	edges.push_back(edge(src,dst,dist(dep,arr)));

	REP(i,n) {
		// wormhole edge itself
		edges.push_back(edge(2*i,2*i+1,wormholes[i].dt,wormholes[i].t0));

		// connect wormhole to src and dst
		edges.push_back(edge(src,2*i,  dist(dep,wormholes[i].start)));
		edges.push_back(edge(2*i+1,dst,dist(arr,wormholes[i].end)));

		// connect wormhole exit to all wormhome entries
		REP(j,n)
			edges.push_back(edge(2*i+1,2*j,dist(wormholes[i].end,wormholes[j].start)));
	}

	V = 2*n+2;
	besttime = vector<int>(V,infty);
	lastedge = vector<int>(V,-1);

	besttime[src] = 0;
}

int relax()
{
	int updated = -1;

	REP(i,(int)edges.size()) {
		edge &e = edges[i];
		int newtime = max(besttime[e.fr],e.t0) + e.dt;
		if ( newtime < besttime[e.to] ) {
			updated = 1;
			besttime[e.to] = newtime;
			lastedge[e.to] = i;
			updated = e.to;
		}
	}

	return updated;
}

int main()
{
	int nruns;

	scanf("%d\n",&nruns);

	for(int run=1; run<=nruns; run++) {
		read_init();

		int ncycle = 0;
		do {
			// saturate all non-cycles:
			lastedge = vector<int>(V,-1);
			REP(i,V-1) relax();

			int c0;
			if ( (c0=relax())>=0 ) {
				// cycle detected, now reconstruct it:
				assert( ++ncycle<=(int)wormholes.size() );

				vector<int> cycle;
				int prev = c0;
				while ( find(ALL(cycle),prev)==cycle.end() ) {
					cycle.push_back(prev);
					prev = edges[lastedge[prev]].fr;
				}
				reverse(ALL(cycle));
				cycle.erase(find(ALL(cycle),prev)+1,cycle.end());

				// saturate cycle to lowest limit:
				int shift = -infty;
				int len = 0;
				REP(i,(int)cycle.size()) {
					edge &e = edges[lastedge[cycle[i]]];
					len += e.dt;
					shift = max(shift,e.t0 + e.dt - besttime[cycle[i]]);
				}
				assert( len<0 );
				REP(i,(int)cycle.size()) besttime[cycle[i]] += shift;
			} else {
				// no relaxation possible: we're done
				break;
			}

		} while ( 1 );

		int res = besttime[dst];
		printf("%d\n",res);
	}

	return 0;
}
