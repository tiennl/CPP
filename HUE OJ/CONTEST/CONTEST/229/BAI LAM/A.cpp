#include <bits/stdc++.h>
using namespace std;

#define M  	1000003
typedef long long int lli;

lli powa(lli a, lli n) {
	if (n == 0) return 1;
	else if (n == 1) return a % M;
	else {
		lli p = powa(a, n/2);
		if (n % 2 == 0) return (p * p) % M;
		else return (((p * p) % M) * a) % M;
	}
}

vector<lli> invs(1000001, -1);
lli inv(lli q) {
	if (invs[q] != -1) return invs[q];
	invs[q] = powa(q, M-2);
	return invs[q];
}

int main(void) {
	//cout << powa(2, 20);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		lli n, k; cin >> n >> k;
		lli r = 1; 
		for (int i = 1; i <= n; i++) r = (r * i) % M; //cout << r << endl; }
		for (int i = 1; i <= k; i++) r = (r * inv(i)) % M; //cout << r << endl; }
		for (int i = 1; i <= n-k; i++) r = (r * inv(i)) % M; //cout << r << endl; }
		cout << "Case " << tc << ": " << r << endl;
	}
	return 0;
}
