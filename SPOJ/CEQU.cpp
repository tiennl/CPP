#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t;
	cin>>t;
	for (int i=1;i<=t;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<"Case "<<i<<": ";
		if (c%__gcd(a,b)==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
