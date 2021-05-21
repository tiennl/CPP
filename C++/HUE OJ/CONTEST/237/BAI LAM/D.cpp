#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(v) cout << #v << ":\t" << v << endl
#define _ << " " <<

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 1e5 + 1;
const ll INF = 1e18 + 7;

ll n, t, k;
vector<pll> g[N];

ll p[N], d[N];
priority_queue<pll> q;

void bfs() {
	fill(d, d + N, INF);
	d[k] = 0;
	q.push({0, k});
	
	while (!q.empty()) {
		ll v = q.top().s;
		q.pop();
		
		for (pll& u: g[v]) {
			ll to = u.s, len = u.f;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({-d[to], to});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (ll i = 1; i < n; ++i) {
		ll x, y, d;
		cin >> x >> y >> d;
		g[x].pb({d, y});
		g[y].pb({d, x});
	}
	
	cin >> t >> k;
	bfs();
	while (t--) {
		ll x, y; cin >> x >> y;
		cout << d[x] + d[y] << "\n";
	}
	
	return 0;
}
