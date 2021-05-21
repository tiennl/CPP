/* Solution to "Room Assignments" from NWERC 2009
 *
 * Author: Per Austrin
 *
 * Algorithm: ad hoc
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
pii req[100000];
vi adj[100000];
int value[100000];

int vis[100000], taken[100000];

int next(int v, int e) { 
  return req[e].first == v ? req[e].second : req[e].first; 
}

bool set(int e, int v) {
  if (taken[v]) return taken[v] == e;
  taken[v] = e;
  for (vi::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
    if (*it != e && !set(*it, next(v, *it))) return false;
  return true;
}

bool dfs(int v, int par) {
  if (vis[v]) return set(par, v) || set(par, next(v, par));
  vis[v] = true;
  for (vi::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
    if (*it != par && !dfs(next(v, *it), *it)) return false;
  return true;
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) adj[i].clear();
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &req[i].first, &req[i].second);
    adj[req[i].first].push_back(i);
    adj[req[i].second].push_back(i);
  }
  for (int i = 1; i <= n; ++i)  
    scanf("%d", value+i);

  memset(vis, 0, sizeof(vis));
  memset(taken, 0, sizeof(taken));

  bool ok = true;
  for (int i = 1; ok && i <= n; ++i)
    if (!vis[i] && !dfs(i, 0)) ok = false;

  if (ok) {
    int f = 0, max1 = 0, max2 = 0;
    for (int i = 1; i <= n; ++i) {
      if (!taken[i]) {
	if (value[i] > value[max1]) max2 = max1, max1 = i;
	else if (value[i] > value[max2]) max2 = i;
      } else if (!f) f = i;
    }
    if (f) max2 = (value[max2] < value[max1] ? f : min(f, max2));
    printf("%d %d\n", min(max1, max2), max(max1, max2));
  } else {
    printf("impossible\n");
  }
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) solve();
  return 0;
}
