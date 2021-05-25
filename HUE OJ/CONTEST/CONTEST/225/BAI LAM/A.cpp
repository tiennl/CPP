#include <bits/stdc++.h>
using namespace std; 

#define lli long long int

lli sqr(long long int x) {
	return x*x;
}

lli solve(vector<lli> x) {
	int n = x.size();
	
	lli sqrs = 0; for (int i = 0; i < n; i++) sqrs += sqr(x[i]);
	sqrs *= (n+1);
	
	vector<lli> sums(n); sums[n-1] = x[n-1];
	for (int i = n-2; i >= 0; i--) sums[i] = sums[i+1] + x[i];
	
	lli prods = 0;
	for (int i = 0; i < n; i++) prods += x[i] * sums[i];
	prods *= -2;
	//cout << sqrs << " " << prods << endl;
	return sqrs + prods;
}

int main(void) {
	//freopen("A.in", "r", stdin);
	int n; cin >> n;
	vector<lli> x(n), y(n); 
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	
	lli r = solve(x) + solve(y);	
	cout << r;
	
	//fclose(stdin);
	return 0;
}
