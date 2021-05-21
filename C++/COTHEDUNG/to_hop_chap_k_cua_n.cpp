#include <bits/stdc++.h>
using namespace std;
long long C(long long n, long long k, long long mod){
	long long c=1;
	if (n==k) return 1;
	k=min(k,n-k);
   	for (int i=1;i<=k;i++,n--){
   		c=c*n/i;
   		if (c>mod) c%=mod;
   	}
  	return c;
}
int main(){
	long long t,n,k,mod=1000003;
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>k;
		cout<<"Case "<<i<<": "<<C(n,k,mod)<<endl;
	}
	return 0;
}
