#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

/*
vector<bool> primes(5000000, true);
void seive(int n = 5000000) {
	for (lli q = 2; q*q <= n; q++) {
		if (primes[q]) {
			for (lli i = q*q; i <= n; i += q) primes[i] = false;
		}
	}
}
*/

int main(void) {
	//seive();
	int N; cin >> N;
	vector<int> r(N+1, 0);

	int c = 0;
	for (int m = 3; m <= 4000; m += 2) {
		for (int n = 1; n < m; n += 2) {
			if (__gcd(m, n) != 1) continue;
			for (int q = m*(m+n); q <= N; q += m*(m+n)) r[q]++;
		}
	}

	cout << count(r.begin(), r.end(), 1);
	
	return 0;
}
