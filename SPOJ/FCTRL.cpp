#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll countLastZeros(ll n){
	ll coun=0;
	for (int i=5;n/i>=1;i*=5)
		coun+=n/i;
	return coun;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n;
	cin>>t;
	while (t--){
		cin>>n;
		cout<<countLastZeros(n)<<endl;
	}
	return 0;	
}
// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
