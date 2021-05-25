#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long int lli;

lli sumsqr(lli n) {	
	lli a = n, b = n+1, c = 2*n+1;
	if (c % 3 == 0) {
		return (((a*b/2) % MOD) * ((c/3) % MOD)) % MOD;
	} else if (a % 3 == 0) {
		if (a % 2 == 0) {
			return (((a/6) % MOD) * ((b*c) % MOD)) % MOD;
		} else {
			return (((c*b/2) % MOD) * ((a/3) % MOD)) % MOD;
		}
	} else if (b % 3 == 0) {
		if (b % 2 == 0) {
			return (((b/6) % MOD) * ((a*c) % MOD)) % MOD;
		} else {
			return (((c*a/2) % MOD) * ((b/3) % MOD)) % MOD;
		}
	}
}

int main(void) {
	//freopen("A.in", "r", stdin);
	double a, b; cin >> a >> b;
	lli x = ceil(a), y = floor(b);
	
	//cout << sumsqr(y) << " " << sumsqr(x-1) << endl;
	cout << (MOD + sumsqr(y) - sumsqr(x-1)) % MOD;
	
	//fclose(stdin);
	return 0;
}
