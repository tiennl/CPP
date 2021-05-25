#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll XOR(ll n){
	if (n%4==0) return n;
	else if (n%4==1) return 1;
	else if (n%4==2) return n+1;
	return 0;
}
int main(){
	FIO
	ll t,s,f,res;
	cin>>t;
	while (t--){
		cin>>s>>f;
		res=XOR(s-1)^XOR(f);
		cout<<res<<endl;
	}
	return 0;
}
