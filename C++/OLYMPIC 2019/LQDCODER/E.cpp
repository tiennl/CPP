#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000 
ll a[N],mod=111539786;
ll solve(ll n){
	ll x1,x2,x3;
	if (n<=N) return a[n]; 
	if (n%2==0){
		x1=solve(n/2);
		x2=solve(n/2-1);
		return (x1*x1+2*x1*x2)%mod;
	}
	else{
		x1=solve((n+1)/2);
		x2=solve((n+1)/2-1);
		return (x1*x1+x2*x2)%mod;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n;
	a[1]=1;
	a[2]=1;
	for (int i=3;i<=N;i++) a[i]=(a[i-1]+a[i-2])%mod;
	cin>>t;
	while (t--){
		cin>>n;
		cout<<solve(n+1)<<endl;
	}
	return 0;
}
