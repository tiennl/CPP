/* NWERC 2009 solution by Jaap Eldering
 * Problem: Simple Polygon
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

typedef int coord;

class point {
public:
	coord x, y;
	int index;

	point() { x = y = 0; }
	point(coord x1, coord y1) { x = x1; y = y1; }

	point operator +=(point a) { x += a.x; y += a.y; return *this; }
	point operator -=(point a) { x -= a.x; y -= a.y; return *this; }
};

point operator +(point a, point b) { return a += b; }
point operator -(point a, point b) { return a -= b; }
coord operator *(point a, point b) { return a.x*b.x + a.y*b.y; }

coord cross(point a, point b) { return a.x*b.y - a.y*b.x; }

vector<point> points;

int operator <(point a, point b)
{
	if ( a.x!=b.x ) return a.x < b.x;
	return a.y < b.y;
}

VI convexhalfhull()
{
  VI upper;

  // sort points on x-coordinate:
  sort(points.begin(),points.end());

  // build upper part of convex hull (including collinear intermediate points):
  upper.push_back(0);
  for(size_t i=1; i<points.size(); i++) {
	  while ( upper.size()>1 &&
	          cross(points[*(upper.end()-1)]-points[*(upper.end()-2)],
	                points[i]               -points[*(upper.end()-2)])>0 ) upper.pop_back();
	  upper.push_back(i);
  }

  return upper;
}

int main()
{
	int run, nruns;

	cin >> nruns;

	for(run=0; run<nruns; run++) {
		int N;
		cin >> N;
		points = vector<point>(N);
		for(int i=0; i<N; i++) {
			cin >> points[i].x >> points[i].y;
			points[i].index = i;
		}

		VI res, used(N,0);

		res = convexhalfhull();

		for(size_t i=0; i<res.size(); i++) used[res[i]] = 1;

		for(int i=N-1; i>=0; i--) if ( !used[i] ) res.push_back(i);

		cout << points[res[0]].index;
		for(size_t i=1; i<res.size(); i++) cout << ' ' << points[res[i]].index;
		cout << endl;
	}

	return 0;
}
