#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 

ll countZeros(ll n){
    ll r=0;
    double k=log(n)/log(5);
    for (int i=1;i<=k;i++)
        r+=n/pow(5,i);
    return r; 
}

int main(){
	FIO
	ll x;
	cin>>x;
	cout<<countZeros(x);
	return 0;
}
