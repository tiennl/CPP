#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n,res=0;
		cin>>n;
		if (n%2!=0) res=(n+3)*(n+3);
		else res=n*n;
		if (res%48>24) res=res/48+1;
		else res/=48;
		cout<<res<<endl;
	}	
	return 0;
}
