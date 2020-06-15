#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll powMod(ll a, ll b, ll p){
    ll r=1;
    a%=p;
    b%=p;
    while (b>0) {
        if (b%2>0) r=r*a%p;
        a=a*a%p;  
        b/=2;
    }
    return r;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll x,n,p=10000;
	cin>>x>>n;
	cout<<powMod(x,n,p);
	return 0;
}
