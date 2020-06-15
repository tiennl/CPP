#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define sqr(x) x*x 
#define N 1000005

ll solve(vector<ll> x){
	ll n=x.size(),sqrs=0;
	for (int i=0;i<n;i++) sqrs+=sqr(x[i]);
	sqrs*=(n+1);
	vector<ll> sums(n); 
	sums[n-1]=x[n-1];
	for (int i=n-2;i>=0; i--) sums[i]=sums[i+1]+x[i];
	ll p=0;
	for (int i=0;i<n;i++) p+=x[i]*sums[i];
	p*=-2;
	return sqrs+p;
}

int main(){
	FIO
	ll n,res=0; 
	cin>>n;
	vector<ll> x(n),y(n); 
	for (int i=0;i<n;i++) cin>>x[i]>>y[i];
	res=solve(x)+solve(y);	
	cout<<res;
	return 0;
}
