#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define f first
#define s second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << ":\t" << x << endl
#define _ << " " <<
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
const ll N = 2e5 + 3;
 
ll t, n, k, a[N];
ll sum, cur;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n >> k;
		for (ll i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		
		if ((sum % 2 == 0 && k % 2) || (sum % 2 && k % 2 == 0)) {
			cout << "NO\n";
			continue;
		}
		
		vector<ll> res;
		cur = 0;
		for (ll i = 1; i <= n; ++i) {
			cur += a[i];
			if (cur & 1) {
				res.pb(i);
				cur = 0;
			}
		}
		
		if ((ll)res.size() < k) {
			cout << "NO\n";
			continue;
		}
		
		while ((ll)res.size() >= k) res.pop_back();
		res.pb(n);
		
		cout << "YES\n";
		for (auto& v: res) cout << v << " ";
		cout << "\n";
	}
	
	return 0;
}
