#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n; cin >> n;
	string s; cin >> s;
	string t = s; reverse(t.begin(), t.end());

	int dp[n+1][n+1];
	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << n - dp[n][n];

	return 0;
}
