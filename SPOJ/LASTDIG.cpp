#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
ll Power(ll a,ll b,ll n){
    ll d=1;
    while (b){
        if (b%2)  
            d=(d*a)%n;
        b>>=1;  
        a=(a*a)%n;
    }
    return d;
}
int main(){
	ll t,a,b;
	cin>>t;
	while (t--){
		cin>>a>>b;
    	cout<<Power(a,b,10)<<endl;
	}
    return 0; 
} 
