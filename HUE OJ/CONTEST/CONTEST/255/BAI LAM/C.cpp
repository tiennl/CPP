#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int len(ll n){
	int r=0;
	while (n>0){
		r++;
		n/=10;
	}	
	return r;
}
int main(){
	FIO
	ll n,f,c=0,res;
	cin>>n;
	for (int i=1;i<=sqrt(n);i++){
		ll j=n/i;
		if (i*j==n){
			f=max(len(i),len(j));
			if (c==0){
				c++;
				res=f;
			}
			else res=min(res,f);
		}
	}
	cout<<res;
	return 0;
}
