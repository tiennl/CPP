#include <bits/stdc++.h>
using namespace std;

#define M	1000000007
typedef long long int lli;

int main(void) {
	lli p, q; cin >> p >> q;
	lli a = p-1, b = q-1;
 	if (a % 2 == 0) a /= 2;
	else b /= 2;

	cout << a * b;
	
	return 0;
}
