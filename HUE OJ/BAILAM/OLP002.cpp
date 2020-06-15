#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll PowMod(ll a, ll b, ll p){
    ll r=1;
    a%=p;
    b%=p-1;
    while (b>0){
        if (b%2>0) 
            r=r*a%p;
        a=a*a%p; 
        b/=2;
    }
    return r;
}

int main(){
	FIO
	ll n,mod=1e9+7;
	cin>>n;
	cout<<PowMod(2,n,mod);
	return 0;
}
