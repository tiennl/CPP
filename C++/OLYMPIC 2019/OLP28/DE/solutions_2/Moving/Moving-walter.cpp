#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct data {
  ll to, t, sf;
  data(ll _to, ll _t, ll _sf) {
    to = _to;
    t = _t;
    sf = _sf;
  }
};

typedef vector<ll> vl;
typedef vector<data> vd;
typedef vector<vd> md;

md adj;
vl freq, result;
ll sumfreq, cost, mincost;

ll dfs1(ll x, ll p, ll c) {
  // update total cost
  cost += c * freq[x];
  // update and return sum of frequencies in subtree pointed to by edge p --> x
  ll sf = freq[x];
  vd::iterator jt = adj[x].end();
  for (vd::iterator it = adj[x].begin() ; it != adj[x].end() ; ++it)
    if (it->to != p)
      sf += it->sf = dfs1(it->to, x, c+it->t);
    else
      jt = it;
  // back edge
  if (jt != adj[x].end())
    jt->sf = sumfreq-sf;
  return sf;
}

void dfs2(ll x, ll p, ll c) {
  if (c == mincost)
    result.push_back(x);
  else if (c < mincost) {
    mincost = c;
    result = vl(1, x);
  }
  for (vd::iterator it = adj[x].begin() ; it != adj[x].end() ; ++it)
    if (it->to != p)
      // add cost difference when moving from x to it->to
      // we could abort if difference > 0
      dfs2(it->to, x, c + (sumfreq-2*it->sf)*it->t);
}

int main() {
  ll k, n;
  cin >> k;
  while (k--) {
    cin >> n;
    adj = md(n+1);
    for (ll i=0 ; i<n-1 ; i++) {
      ll a, b, t;
      cin >> a >> b >> t;
      adj[a].push_back(data(b, t, 0));
      adj[b].push_back(data(a, t, 0));
    }
    freq = vl(n+1);
    sumfreq = 0;
    ll m;
    cin >> m;
    while (m--) {
      ll a, f;
      cin >> a >> f;
      sumfreq += freq[a] = f;
    }
    if (n == 1) {
      cout << 0 << endl << 1 << endl;
      continue;
    }
    mincost = 1ll<<60;
    result.clear();
    // find a leaf
    for (ll i=1 ; i<=n ; i++)
      if (adj[i].size() == 1) {
        // determine costs when living at i
        // annotate each edge with sum of frequencies of all following nodes
        cost = 0;
        dfs1(i, -1, 0);
        // find places with minimum cost
        dfs2(i, -1, cost);
        break;
      }
    assert(mincost < 1ll<<60);
    sort(result.begin(), result.end());
    cout << 2*mincost << endl;
    for (vl::iterator it = result.begin() ; it != result.end() ; ++it)
      cout << (it == result.begin() ? "" : " ") << *it;
    cout << endl;
  }
  return 0;
}

