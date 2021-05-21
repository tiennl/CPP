#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int a, b, d; cin >> a >> b >> d;
		if (d % __gcd(a,b) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
