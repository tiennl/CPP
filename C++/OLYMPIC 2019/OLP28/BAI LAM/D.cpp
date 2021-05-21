#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	while (cin>>n){
		ll res=0;
		while (n%2==0) n/=2,res++;
		for (ll i=3;i<=sqrt(n);i+=2)
			while (n%i==0) n/=i,res++;
		if (n>2) res++;
		cout<<res<<endl;
	}
	return 0;
}
