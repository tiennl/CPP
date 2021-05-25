#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << " " << x << "\n"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, m;
	while (cin >> n >> m) {
		if (m == 0) {
			cout << m << " does not divide " << n << "!" << endl;
			continue;
		}
		
		map<ll, ll> uc;
		ll tmp = m;
		for (ll i = 2; i * i <= tmp; ++i) {
			while (tmp % i == 0) {
				++uc[i];
				tmp /= i;
			}
		}
		if (tmp > 1) ++uc[tmp];
		
		for (auto& v: uc) {
			ll x = v.f;
			while (x <= n) {
				v.s -= n / x;
				x *= v.f;
			}
			
			if (v.s > 0) {
				cout << m << " does not divide " << n << "!";
				goto lap;
			}
		}
		cout << m << " divides " << n << "!";

		lap:;
		cout << endl;
	}
	
	return 0;
}
