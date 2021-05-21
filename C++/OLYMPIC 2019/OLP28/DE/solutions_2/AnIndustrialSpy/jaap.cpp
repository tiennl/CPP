/* NWERC 2009 solution by Jaap Eldering
 * Problem: An Industrial Spy
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;

const int maxprime = 4000;
VI primes;

void findprimes()
{
	primes.push_back(2);

	for(int p=3; p<=maxprime; p+=2) {
		int i;
		for(i=0; primes[i]*primes[i]<=p; ++i)
			if ( p%primes[i]==0 ) break;
		if ( primes[i]*primes[i]>p ) primes.push_back(p);
	}
}

int isprime(int x)
{
	if ( x<=1 ) return 0;
	for(int i=0; primes[i]*primes[i]<=x; ++i)
		if ( x%primes[i]==0 ) return 0;
	return 1;
}

string digitstr;
VI digits, used;
int nsol;

void dfs(int n)
{
	if ( isprime(n) ) nsol++;

	for(int i=0; i<(int)digits.size(); i++) {
		if ( n==0 && i==0 ) continue; // Don't add prefix zero's
		if ( used[i]<digits[i] ) {
			used[i]++;
			dfs(10*n+i);
			used[i]--;
		}
	}
}

int main()
{
	int run, nruns;

	findprimes();

	cin >> nruns;

	for(run=0; run<nruns; run++) {
		cin >> digitstr;

		used = digits = VI(10,0);
		for(int i=0; i<(int)digitstr.length(); i++) digits[digitstr[i]-'0']++;

		nsol = 0;
		dfs(0);
		cout << nsol << endl;
	}

	return 0;
}
