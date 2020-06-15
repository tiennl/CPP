#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t,n;
	cin>>t;
	while (t--){
		cin>>n;
		for (ll i=n/2;i>=0;i--)
			if (__gcd(n,i)==1){
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}
