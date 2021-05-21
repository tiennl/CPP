// Author: Adrian Kuegel
// Algorithm: Graham Scan
// Complexity: O(n log n)

#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;

#define DET(a, b, c, d) ((a)*(d) - (b)*(c))
#define MAXN 2000

struct point {
	int x, y;
}p[MAXN];

bool comp(int a, int b) {
	if (p[a].x != p[b].x)
		return p[a].x < p[b].x;
	return p[a].y < p[b].y;
}

int ccw(const point &a, const point &b, const point &c) {
	return DET(b.x - a.x, c.x - a.x, b.y - a.y, c.y - a.y);
}

int ind[MAXN];
int ch[MAXN];

int main() {
	int tc, n;
	scanf("%d", &tc);
	assert(tc > 0 && tc < 200);
	while(tc--) {
		scanf("%d", &n);
		assert(n >= 3 && n <= MAXN);
		for (int i=0; i<n; ++i) {
			scanf("%d %d", &p[i].x, &p[i].y);
			assert(p[i].x >= -10000 && p[i].x <= 10000 && p[i].y >= -10000 && p[i].y <= 10000);
			ind[i] = i;
		}
		sort(ind, ind + n, comp);
		// check that no two points are equal
		for (int i=1; i<n; ++i)
			assert(p[ind[i-1]].x != p[ind[i]].x || p[ind[i-1]].y != p[ind[i]].y);
		int l = 1;
		ch[0] = ind[0];
		ch[1] = ind[1];
		for (int i=2; i<n; ++i) {
			while(l > 0 && ccw(p[ch[l-1]], p[ch[l]], p[ind[i]]) > 0)
				--l;
			ch[++l] = ind[i];
		}
		// check that not all points are collinear
		if (l+1 == n) {
			bool collinear = true;
			for (int i=2; i<n; ++i)
				if (ccw(p[ind[i-2]], p[ind[i-1]], p[ind[i]]) != 0) {
					collinear = false;
					break;
				}
			assert(!collinear);
		}
		for (int i=0; i<=l; ++i) {
			if (i) printf(" ");
			printf("%d", ch[i]);
		}
		for (int i=n-1; i>0; --i) {
			if (ch[l] == ind[i])
				--l;
			else
				printf(" %d", ind[i]);
		}
		puts("");
	}
	return 0;
}
