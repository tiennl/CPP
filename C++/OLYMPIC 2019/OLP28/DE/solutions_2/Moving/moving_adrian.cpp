#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 50000

struct edge {
	int dest, len;
}E;

typedef vector<edge> VE;
VE adj[MAXN];
int st_cnt[MAXN], node_cnt[MAXN];

int getSubtreeCnt(int cur, int par, long long &ccost) {
	assert(st_cnt[cur] == -1);
	st_cnt[cur] = node_cnt[cur];
	for (VE::iterator it=adj[cur].begin(); it!=adj[cur].end(); ++it)
		if (it->dest != par) {
			int t = getSubtreeCnt(it->dest, cur, ccost);
			st_cnt[cur] += t;
			ccost += (long long)t * it->len;
		}
	return st_cnt[cur];
}

long long best;
vector<int> sol;

void dfs(int cur, int par, int cnt, long long cur_cost) {
	if (cur_cost < best) {
		best = cur_cost;
		sol.clear();
	}
	if (cur_cost == best)
		sol.push_back(cur);
	for (VE::iterator it=adj[cur].begin(); it!=adj[cur].end(); ++it) {
		if (it->dest != par) {
			int cnt2 = cnt + st_cnt[cur] - st_cnt[it->dest];
			dfs(it->dest, cur, cnt2, cur_cost + (cnt2 - st_cnt[it->dest]) * (long long)it->len);
		}
	}
}

int main() {
	int tc, n;
	scanf("%d", &tc);
	assert(tc > 0 && tc <= 200);
	while(tc--) {
		scanf("%d", &n);
		assert(n <= MAXN && n > 0);
		for (int i=0; i<n; ++i) {
			adj[i].clear();
			st_cnt[i] = -1;
			node_cnt[i] = 0;
		}
		for (int i=1; i<n; ++i) {
			int a, b;
			scanf("%d %d %d", &a, &b, &E.len);
			assert(a > 0 && a <= n);
			assert(b > 0 && b <= n);
			assert(E.len > 0 && E.len <= 300);
			--a;
			--b;
			E.dest = a;
			adj[b].push_back(E);
			E.dest = b;
			adj[a].push_back(E);
		}
		int m;
		scanf("%d", &m);
		assert(m >= 0 && m <= n);
		while(m--) {
			int a, f;
			scanf("%d %d", &a, &f);
			assert(a > 0 && a <= n && f > 0 && f <= 500);
			--a;
			assert(node_cnt[a] == 0);
			node_cnt[a] = f;
		}
		long long ccost = 0;
		getSubtreeCnt(0, -1, ccost);
		best = 1LL<<62;
		dfs(0, -1, 0, ccost);
		printf("%lld\n", best * 2);
		sort(sol.begin(), sol.end());
		for (int i=0; i<(int)sol.size(); ++i) {
			if (i) printf(" ");
			printf("%d", sol[i] + 1);
		}
		puts("");
	}
	return 0;
}
