#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
#define mod 1000000007
ll powMod(ll x, int n){
	ll r=1,temp=x%mod;
	while (n){
		if (n&1) r=(r*temp)%mod;
		n>>=1;
		temp=(temp*temp)%mod;
	}
	return r%mod;
}
int main(){
	FIO
	ll t,n;
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		if (n==1){
			cout<<"Case 1: "<<1<<endl;
			continue;
		}
		n--;
		ll res=powMod(2,n-1);
		res=(res*(n+2))%mod;
		cout<<"Case "<<i<<": "<<res<<endl;
	}
	return 0;
}
