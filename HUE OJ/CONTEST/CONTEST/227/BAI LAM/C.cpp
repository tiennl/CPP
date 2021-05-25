#include <bits/stdc++.h>
using namespace std;

#define MAX (int)(1e8+1)

typedef long long int lli;

lli n, k; 
lli rank(lli X) {
	lli r = 0;
	for (lli i = 1; i <= n; i++) {
		r += min(n, (X > i*i ? (lli)sqrt(X - i*i) : 0));
		//cout << r << endl;
	}
	return r;
}

int main(void) {
	cin >> n >> k;
	
	lli L = 2, R = 2*n*n, mr = (lli)1e15, mx = -1;
	while (L <= R) {
		lli X = (L+R) / 2;
		lli rX = rank(X);
		//cout << X << " " << rX << endl;
		if (rX >= k) {
			if (mr >= rX) {
				mr = rX;
				mx = X;
			}
			R = X-1;
		} else L = X+1;
	}
	cout << mx;
	
	return 0;
}
