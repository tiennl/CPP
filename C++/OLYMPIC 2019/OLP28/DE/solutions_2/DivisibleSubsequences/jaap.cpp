/* NWERC 2009 solution by Jaap Eldering
 * Problem: Divisible subsequences
 */

#include <iostream>
#include <map>

using namespace std;

long long sqr2(int n) { return (long long)n*(n-1)/2; }

int main()
{
	int run, nruns;

	cin >> nruns;

	for(run=0; run<nruns; run++) {
		int D, N;
		cin >> D >> N;
		int x, d = 0;
		map<int,int> freq;
		freq[0] = 1;
		for(int i=0; i<N; i++) {
			cin >> x;
			d = (d+x)%D;
			freq[d]++;
		}

		long long res = 0;
		for(map<int,int>::iterator it=freq.begin(); it!=freq.end(); ++it) res += sqr2(it->second);

		cout << res << endl;
	}

	return 0;
}
