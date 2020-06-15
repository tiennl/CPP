#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll f[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,base=1e6+7;
	cin>>n;
	f[1]=1;
	f[2]=1;
	for (int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%base;
	cout<<f[n];
	return 0;
}
