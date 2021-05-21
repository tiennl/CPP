#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mod(a) (a) % MOD
typedef long long int lli;
typedef vector< vector<lli> > vvi;
typedef vector<lli> vi;

vvi mul(vvi v1, vvi v2, int n, int p, int m) {
	vvi r(n, vi(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < p; k++) {
				r[i][j] = mod(r[i][j] + v1[i][k] * v2[k][j]);
			}
		}
	}
	return r;
}

vvi pow(vvi v, int n) {
	if (n == 1) return v;
	else {
		vvi v2 = pow(v, n/2);
		vvi mv2 = mul(v2, v2, 3, 3, 3);
		return (n % 2 == 0) ? mv2 : mul(mv2, v, 3, 3, 3);
	}
}

int main(void) {
	//freopen("B.in", "r", stdin);
	lli n; cin >> n;
	
	vvi v(3, vi(3, 0));
	v[0][0] = 0; v[0][1] = 0; v[0][2] = 1;
	v[1][0] = 1; v[1][1] = 0; v[1][2] = 1;
	v[2][0] = 0; v[2][1] = 1; v[2][2] = 1;
	
	vvi bv(1, vi(3, 0));
	bv[0][0] = 1; bv[0][1] = 2; bv[0][2] = 4;
	vvi pv = mul(bv, pow(v, n-1), 1, 3, 3);
		
	cout << pv[0][0];
	
	fclose(stdin);
	return 0;
}
