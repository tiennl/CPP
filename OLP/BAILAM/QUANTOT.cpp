#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll n,a,b,ok=0,res=1e9;
	cin>>n>>a>>b;
	if (n%b==0){
		cout<<n/b;
		return 0;
	}
	for (int i=0;i<=n/b;i++){
		ll j=n-i*b;
		if (j>=0 && j%a==0){
			res=min(res,i+j/a);
			ok=1;
		}
	}
	if (ok==0) cout<<-1;
	else cout<<res;
	return 0;
}
