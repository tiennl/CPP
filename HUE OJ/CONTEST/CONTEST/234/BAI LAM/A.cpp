#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(v) cout << #v << ":\t" << v << endl

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, t;
	cin >> n >> t;
	ll a[n];
	for (ll i = 0; i < n; ++i) cin >> a[i];
	
	ll res = 0;
	for (ll i = 2; i < n; ++i) {
		ll id = lower_bound(a, a + i, a[i] - t) - a;
		if (id > i-2) continue;
		ll cnt = i - id;
		res += cnt * (cnt - 1) / 2;
	}
	cout << res;
	
	return 0;
}
