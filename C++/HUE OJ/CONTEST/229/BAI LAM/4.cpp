#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 3e6 + 3;

ll n, res;

vector<ll> p;
vector<ll> is_p(N, true);

void prime() {
	for (ll i = 2; i < N; ++i) {
        if (is_p[i]) p.push_back(i);

        for (ll j = 0; j < p.size(); ++i) {
			if (i * p[j] < N) is_p[i * p[j]] = false;
			if (i % p[j] == 0) break;
        }
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0);

	cin >> n;
	prime();

	res = 0;
	for (ll i = 0; p[i]*p[i] <= n && i < p.size(); ++i) {
		if (n % p[i] == 0) {
			cout<<p[i]<<" ";
			n /= p[i--];
			++res;
	
		}
	}
	if (n != 1) ++res;

	cout << res;

	return 0;
}
