#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll a[10000];
int main(){
	FIO
	ll n,m,res=0;
	cin>>n>>m;
	for (int i=1;i<=n+m;i++) a[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			a[i+j]++;
			res=max(res,a[i+j]);
		}
	for (int i=1;i<=n+m;i++)
		if (a[i]==res) cout<<i<<endl;
	return 0;
}
