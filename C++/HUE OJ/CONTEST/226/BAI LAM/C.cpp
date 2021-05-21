#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mod(a) a % MOD
typedef long long int lli;

int main(void) {
	//freopen("A.in", "r", stdin);
	lli n; cin >> n;
	
	vector<lli> a(4);
	for (int i = 0; i < 4; i++) {
		a[i] = n+i;
		if (a[i] % 4 == 0) a[i] /= 4;
		a[i] = mod(a[i]);
	}
	cout << mod(mod(mod(a[0]*a[1])*a[2])*a[3]);
	
	//fclose(stdin);
	return 0;
}
