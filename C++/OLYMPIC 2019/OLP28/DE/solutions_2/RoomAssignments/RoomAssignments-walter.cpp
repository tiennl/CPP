#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;

vi comp;
mi adj;

void dfs(int n, int c) {
  comp[n] = c;
  for (vi::iterator it = adj[n].begin() ; it != adj[n].end() ; ++it)
    if (comp[*it] < 0)
      dfs(*it, c);
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    adj = mi(n);
    for (int i=0 ; i<n-1 ; i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vi rat(n);
    for (int i=0 ; i<n ; i++)
      cin >> rat[i];
    int ncomp = 0;
    comp = vi(n, -1);
    for (int i=0 ; i<n ; i++)
      if (comp[i] < 0)
        dfs(i, ncomp++);
    vi nodes(ncomp), edges(ncomp);
    for (int i=0 ; i<n ; i++) {
      ++nodes[comp[i]];
      edges[comp[i]] += adj[i].size();
    }
    vi tree, cycle, wrong;
    for (int i=0 ; i<ncomp ; i++) {
      assert(edges[i] % 2 == 0);
      edges[i] /= 2;
      if (nodes[i] < edges[i])
        wrong.push_back(i);
      else if (nodes[i] == edges[i])
        cycle.push_back(i);
      else {
        assert(nodes[i] == edges[i]+1);
        tree.push_back(i);
      }
    }
    if (wrong.size() > 0) {
      cout << "impossible" << endl;
      continue;
    }
    assert(tree.size() == 1);
    int maxel = -1;
    for (int i=0 ; i<n ; i++)
      if (comp[i] == tree[0])
        if (maxel<0 || rat[i] > rat[maxel])
          maxel = i;
    assert(maxel >= 0);
    int other = -1;
    if (ncomp == 1) {
      for (int i=0 ; i<n ; i++)
        if (i != maxel && comp[i] == tree[0])
          if (other<0 || rat[i] > rat[other])
            other = i;
    } else {
      for (int i=0 ; i<n ; i++)
        if (comp[i] != tree[0] || (i != maxel && rat[i] == rat[maxel])) {
          other = i;
          break;
        }
    }
    assert(other >= 0);
    cout << min(maxel, other)+1 << " " << max(maxel, other)+1 << endl;
  }
  return 0;
}

