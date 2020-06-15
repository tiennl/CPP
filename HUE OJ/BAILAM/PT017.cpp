#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll sum(ll n){
	ll r=0;
	while (n>0){
		r+=n%10;
		n/=10;
	}
	return r;
}

int main(){
	FIO
	ll n,a,b,res=0;
	cin>>n>>a>>b;
	for (int i=1;i<=n;i++)
		if (sum(i)>=a && sum(i)<=b) res+=i;
	cout<<res;
	return 0;
}
