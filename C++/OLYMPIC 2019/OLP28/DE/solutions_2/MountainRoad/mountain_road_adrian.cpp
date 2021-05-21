// Author: Adrian Kuegel
// Algorithm: Dynamic Programming
// Complexity: O(n^3)

#include <stdio.h>
#include <utility>
#include <algorithm>
#include <assert.h>
using namespace std;

#define INF 1000000000
typedef pair<int, int> PII;

PII cars[2][200];
int dp[201][201][2];

int main() {
	int tc;
	scanf("%d", &tc);
	assert(tc >= 1 && tc <= 200);
	while(tc--) {
		int N;
		scanf("%d", &N);
		assert(N > 0 && N <= 200);
		int n[2] = {0, 0}, lastt = -1, t, d;
		char type;
		while(N--) {
			scanf(" %c %d %d", &type, &t, &d);
			assert(type == 'A' || type == 'B');
			assert(t > lastt && t <= 100000);
			assert(d > 0 && d <= 100000);
			cars[type-'A'][ n[type-'A']++ ] = PII(t, d);
			lastt = t;
		}
		for (int i=0; i <= n[0]; ++i)
			for (int j=0; j <= n[1]; ++j)
				dp[i][j][0] = dp[i][j][1] = INF;
		dp[0][0][0] = dp[0][0][1] = 0;
		for (int i=0; i <= n[0]; ++i)
			for (int j=0; j <= n[1]; ++j)
				for (int k=0; k<2; ++k) {
					int last_end = dp[i][j][k] - 10;
					int last_start = last_end;
					for (int l= k? j : i; l<n[k]; ++l) {
						int next_start = max(last_start + 10, cars[k][l].first);
						int next_end = max(next_start + cars[k][l].second, last_end + 10);
						if (k)
							dp[i][l+1][0] = min(dp[i][l+1][0], next_end);
						else
							dp[l+1][j][1] = min(dp[l+1][j][1], next_end);
						last_start = next_start;
						last_end = next_end;
					}
				}
		printf("%d\n", min(dp[ n[0] ][ n[1] ][0], dp[ n[0] ][ n[1] ][1]));
	}
	return 0;
}
