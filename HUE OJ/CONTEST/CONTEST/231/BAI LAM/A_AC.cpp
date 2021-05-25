#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(void) {
	cout << fixed << setprecision(5);
	lli p, q, r, s; 
	while (cin >> p >> q >> r >> s) {
		long double v = 1;
		long double i = p-q+1, j = r-s+1, k = 1, l = 1;
		while (i <= p && j <= r) { v = v * (i / j); i++; j++; }
		while (k <= s && l <= q) { v = v * (k / l); k++; l++; }

		while (i <= p || k <= s || j <= r || l <= q) {
			if (i <= p) { v = v * i; i++; }
			if (k <= s) { v = v * k; k++; }
			if (j <= r) { v = v / j; j++; }
			if (l <= q) { v = v / l; l++; }
		}
		
		cout << v << endl;
	}
	return 0;
}
