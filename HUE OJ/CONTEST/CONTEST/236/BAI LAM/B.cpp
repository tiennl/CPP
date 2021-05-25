#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
vector< vector<lli> > Cm(32, vector<lli>(32, 0));
lli C(int n, int k) {
	if (n == 1 || k == 0) return 1;
	else if (n < k) return 0;
	else if (n == k) return 1;
	else if (Cm[n][k] != 0) return Cm[n][k];
	else {
		Cm[n][k] = C(n-1,k-1) + C(n-1,k);
		return Cm[n][k];
	}
}

int main(void) {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n, k; cin >> n >> k;
		lli r = 0;
		for (int i = 0; i < n; i++) { r += C(n, n-1-i) * C(k-1, i); }
		cout << r << endl;
	}
	return 0;
}
