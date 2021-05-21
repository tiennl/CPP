// Author: Adrian Kuegel
// Algorithm: sieve of Erathosthenes + brute force
// Complexity: O(l!) (l = number of digits)

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <set>
using namespace std;

char p[10000000], digs[10];

int main() {
	// generate primes up to 9999999
	for (int i=4; i<10000000; i+=2)
		p[i] = 1;
	p[0] = p[1] = 1;
	for (int i=3; i<3200; i+=2)
		if (!p[i])
			for (int j=i*i; j<10000000; j+=i+i)
				p[j] = 1;
	int tc;
	scanf("%d", &tc);
	assert(tc > 0 && tc <= 200);
	while(tc--) {
		assert(scanf("%s", digs) == 1);
		int l = strlen(digs);
		assert(l <= 7);
		sort(digs, digs + l);
		assert(digs[0] >= '0' && digs[l-1] <= '9');
		set<int> primes;
		do {
			int num = 0;
			for (int i=0; i<l; ++i) {
				num = num * 10 + digs[i] - '0';
				if (!p[num])
					primes.insert(num);
			}
		}while(next_permutation(digs, digs + l));
		printf("%d\n", (int)primes.size());
	}
	return 0;
}
