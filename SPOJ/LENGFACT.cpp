#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define db double 
#define N 1000005
#define pi 2*acos(0)
#define ln10 2.7182818284590452353 

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n,res=0;
		cin>>n;
		if (n<3) cout<<1<<endl;
		else{
			res=ceil(log10(2*pi*n)/2+n*log10(n/ln10));
			cout<<res<<endl;
		}
	}
	return 0;
}
