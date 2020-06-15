#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n,res=0;
		cin>>n;
		for (int i=1;i<=sqrt(n);i++)
			if (n%i==0){
				if (n/i==i) res+=i;
				else res+=i+n/i;
			}
		res-=n;
		cout<<res<<endl;
	}
	return 0;
}
