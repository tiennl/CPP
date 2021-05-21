#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

const double N = 2e5 + 3;
const ll M = 1e6 + 3;

double pow_mod(ll a, ll x) {
	ll r = 1;
	while (x) {
		if (x & 1) r = r * a % M;
		a = a * a % M;
		x >>= 1;
	}
	return r;
}

ll test, n, k,r,s;
ll nu, de, nu2,de2;
double s1,s2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> test;
	for (ll t = 1; t <= test; ++t) {
		nu = de = 1;
		nu2= de2= 1;
		cin >> n >> k >> r>>s;
		
		for (ll i = n - k + 1; i <= n; ++i) {
			nu = nu * i % M;
		}
		for (ll i = 1; i <= k; ++i) {
			de = de * i % M;
		}
		de = pow_mod(de, M - 2);
		
		s1=nu * de % M;
		
		for (ll i = r - s + 1; i <= r; ++i) {
			nu2 = nu2 * i % M;
		}
		for (ll i = 1; i <= s; ++i) {
			de2 = de2 * i % M;
		}
		de2 = pow_mod(de2, M - 2);
		
		s2=nu2 * de2 % M;
		cout<<s1/s2<<endl;
	}
	
	return 0;
}
