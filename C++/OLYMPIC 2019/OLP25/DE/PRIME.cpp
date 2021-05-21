#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
bool isPrime[N];

void Eratos() {
	for (int i = 2; i < N; ++i) isPrime[i] = true;
	for (int i = 2; i < N; ++i) if (isPrime[i]) {
 		for (long long j = 1ll * i * i; j < N; j += i) isPrime[j] = false;
	}
}

int main() {
 int n;
 cin >> n;
 Eratos();
 while (n--) {
 	int a, b;
	cin >> a >> b;
	long long sum = 0, cnt = 0;
	for (int i = a; i <= b; ++i) {
		if (isPrime[i]) sum += i, ++cnt;
	}
	if (cnt == 0) cout << 0 << '\n';
	else cout << fixed << setprecision(2) << 1.0 * sum / cnt << '\n'; 
 }
}
