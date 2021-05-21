// Author: Adrian Kuegel
#include <stdio.h>
#include <assert.h>

int cnt[1000000], a[50000];

int main() {
	int tc;
	scanf("%d", &tc);
	assert(tc > 0 && tc <= 200);
	while(tc--) {
		int d, n, sum = 0, res = 0;
		scanf("%d %d", &d, &n);
		assert(d >= 1 && d <= 1000000);
		assert(n >= 1 && n <= 50000);
		cnt[0] = 1;
		for (int i=0; i<n; ++i) {
			scanf("%d", &a[i]);
			assert(a[i] > 0 && a[i] <= 1000000000);
			sum = (sum + a[i]) % d;
			res += cnt[sum]++;
		}
		for (int i=sum=0; i<n; ++i) {
			sum = (sum + a[i]) % d;
			--cnt[sum];
		}
		printf("%d\n", res);
	}
	return 0;
}
