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

const ll M= 1e9 + 7;

map<ll, ll> fib;

ll f(ll n) {
	if (fib.count(n)) return fib[n];
	if (n == 1 || n == 2) return fib[n] = 1;
	
	ll x = n >> 1;
	if (n & 1)
		return fib[n] = (f(x) * f(x) % M + f(x+1) * f(x+1) % M) % M;
	else
		return fib[n] = (f(x) * f(x+1) % M + f(x-1) * f(x) % M) % M;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fib[0] = 0;
	
	ll a, n;
	cin >> a >> n;
	cout << ((f(n + 2) - 1 + M) % M * a % M) % M;
	
	return 0;
}
