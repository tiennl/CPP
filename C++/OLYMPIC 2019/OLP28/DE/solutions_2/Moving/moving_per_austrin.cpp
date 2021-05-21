/* Sample solution to "Moving to Stockholm"
 */
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

// (destination, time) for edges
typedef pair<int, int> edge;
// adjacency list
typedef vector<edge> adjlist;

typedef long long ll;

ll f[100000], totf[100000], tott[100000], TOTf;
adjlist adj[100000];

// Get total travel times for all subtrees
void pull(int v, int par) {
  totf[v] = f[v];
  tott[v] = 0;
  for (adjlist::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
    if (it->first != par) {
      pull(it->first, v);
      totf[v] += totf[it->first];
      tott[v] += tott[it->first] + totf[it->first]*it->second;
    }
  }
}

// Add travel times for nodes reachable from parent
void push(int v, int par, ll t) {
  tott[v] += t;
  for (adjlist::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
    if (it->first != par) {
      ll del = tott[it->first] + totf[it->first]*it->second;
      ll add = (TOTf - totf[it->first])*it->second;
      push(it->first, v, tott[v] - del + add);
    }
  }
}

bool solve() {
  int N, M;
  if (scanf("%d", &N) != 1) assert(0);
  assert(N >= 1 && N <= 50000);
  if (!N) return false;
  fprintf(stderr, "go case N = %d\n", N);
  TOTf = 0;
  for (int i = 1; i <= N; ++i)
    adj[i].clear(), f[i] = 0;
  for (int i = 1; i < N; ++i) {
    int a, b, t;
    scanf("%d%d%d", &a, &b, &t);
    assert(1 <= a && a <= N);
    assert(1 <= b && b <= N && a != b);
    assert(1 <= t && t <= 300);
    adj[a].push_back(edge(b, t));
    adj[b].push_back(edge(a, t));
  }
  scanf("%d", &M);
  assert(0 <= M && M <= N);
  for (int i = 0; i < M; ++i) {
    int a, ff;
    scanf("%d%d", &a, &ff);
    assert(1 <= a && a <= N);
    assert(1 <= ff && ff <= 500);
    assert(f[a] == 0);
    f[a] = ff;
    TOTf += ff;
  }
  pull(1, 0);
  push(1, 0, 0);
  
  ll best = 1LL<<60;
  for (int i = 1; i <= N; ++i)
    best = min(best, tott[i]);

  fprintf(stderr, "  ans is %lld\n", 2*best);

  // Answer is twice the cost since we're going home as well
  printf("%lld\n", 2*best);

  bool first = true;
  for (int i = 1; i <= N; ++i) {
    if (tott[i] == best) {
      if (!first) printf(" ");
      printf("%d", i);
      first = false;
    }
  }
  printf("\n");
  
  return true;
}


int main(void) {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) solve();
  return 0;
}
