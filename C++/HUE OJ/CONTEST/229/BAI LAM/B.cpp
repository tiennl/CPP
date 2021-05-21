#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
typedef long long int lli;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void) {
	int t; cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n; cin >> n;
		long double x = 0.0, y = 0.0, angle = PI / 2;
		for (int i = 0; i < n; i++) {
			string s; long double q; cin >> s >> q;
			switch (s[0]) {
				case 'l': 
					angle += q * PI / 180.0;
					break;
				case 'r': 
					angle -= q * PI / 180.0;
					break;
				case 'f':
					x += q * cos(angle);
					y += q * sin(angle);
					break;
				case 'b':
					x += q * cos(angle + PI);
					y += q * sin(angle + PI);
					break;
			}
		}
		//cout << x << " " << y << " ";
		cout << (int)round(sqrt(x*x + y*y)) << endl;
		//printf("%.0f\n", sqrt(x*x + y*y));
	}
	return 0;
}
