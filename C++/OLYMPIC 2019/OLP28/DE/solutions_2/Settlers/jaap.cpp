/* NWERC 2009 solution by Jaap Eldering
 * Problem: Settlers of Catan
 */

using namespace std;
#include <iostream>
#include <vector>
#include <map>

const int totres = 5;

const int dx[6] = { 1, 0,-1,-1, 0, 1 };
const int dy[6] = { 0, 1, 1, 0,-1,-1 };

struct point {
	int x, y;

	point(int _x, int _y): x(_x), y(_y) {}

	point next(int d)
	{
		point res = *this;
		res.x += dx[d];
		res.y += dy[d];
		return res;
	}
};

int operator <(point a, point b)
{
	if ( a.x!=b.x ) return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	int nruns;

	cin >> nruns;

	for(int run=1; run<=nruns; run++) {
		map<point,int> mapres;
		vector<int> nres(5);
		int n;

		cin >> n;
		if ( n==1 ) {
			cout << "1\n";
			continue;
		}

		point start(0,0);
		mapres[start] = 0;
		nres[0]++;

		int i = 1, dir = 2;
		point curr(1,0);
		for(; i<n; i++) {
			if ( mapres.count(curr.next((dir+1)%6))==0 ) dir = (dir+1)%6;
			curr = curr.next(dir);

			vector<int> used(totres);
			for(int d=0; d<6; d++)
				if ( mapres.count(curr.next(d)) ) used[mapres[curr.next(d)]] = 1;

			int bestres = -1;
			for(int r=0; r<totres; r++)
				if ( !used[r] && ( bestres==-1 || nres[r]<nres[bestres]) ) bestres = r;

			mapres[curr] = bestres;
			nres[bestres]++;
		}

		cout << mapres[curr]+1 << endl;
	}

	return 0;
}
