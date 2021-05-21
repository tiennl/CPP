#include<bits/stdc++.h>
using namespace std;
long long b[1000001];
main(){
	int n, k;
	cin>>n>>k;
	long long a, d=0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		b[a % k]++;
	}
	if (b[0] > 0) d++;
  	if (k % 2 == 0 && (b[k/2] != 0)) d++;
	for (int i = 1; i <= (k - 1)/2; i++) {
		d+= max(b[i], b[k-i]);
	}
	cout<<d;
	return 0;
}
