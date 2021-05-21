#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll N = 1000003;
const ll M = 3*N + 8;
 
bool is_co[M];
ll res[N];
 
void init() {
	is_co[1] = true;
	for (ll i = 2; i < M; ++i) {
		if (is_co[i]) continue;
		for (ll j = i * i; j < M; j += i) is_co[j] = true;
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
 
	res[0] = 0;
	for (ll i = 1; i < N; ++i) {
		res[i] = res[i-1];
		if (!is_co[3*i + 7]) ++res[i];
	}
 
	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		cout << res[n] << "\n";
	}
 
	return 0;
}
