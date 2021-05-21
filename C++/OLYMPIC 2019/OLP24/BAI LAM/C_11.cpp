#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	double res=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		k=i;
		res+=((__gcd(k,n))*cos(2*3.1416*k/n));
	}
	cout<<(long long)res;
	return 0;
}
