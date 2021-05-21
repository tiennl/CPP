#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll x,y;
	cin>>x>>y;
	x*=4;
	if (y<x/2 || x<y){
		cout<<0<<" "<<0;
		return 0;
	}
	if ((x-y)%2==0) cout<<(x-y)/2<<" "<<((2*y)-x)/4;
	else cout<<0<<" "<<0;
	return 0;
}
