#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll a,b;
		cin>>a>>b;
		cout<<b/__gcd(a,b)<<" "<<a/__gcd(a,b)<<endl;
	}	
	return 0;
}
