#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[10];

int main(){
	FIO
	ll n,mod=1e9+7;
	cin>>n;
	for (int i=1;i<=4;i++){
		a[i]=n+i-1;
		if (a[i]%4==0) a[i]/=4;
		a[i]=a[i]%mod;
	}
	cout<<(((((a[1]*a[2])%mod)*a[3])%mod)*a[4])%mod;
	return 0;
}
