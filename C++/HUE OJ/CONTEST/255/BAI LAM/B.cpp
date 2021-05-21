#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll a[100],b[100],c[100],d[100];
int main(){
	FIO
	ll n,m,res,mres;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for (int i=1;i<=m;i++) cin>>c[i]>>d[i];
	for (int i=1;i<=n;i++){
		mres=abs(a[i]-c[1])+abs(b[i]-d[1]);
		res=1;
		for (int j=2;j<=m;j++)
			if (abs(a[i]-c[j])+abs(b[i]-d[j])<mres){
				mres=abs(a[i]-c[j])+abs(b[i]-d[j]);
				res=j;
			}
		cout<<res<<endl;
	}
	return 0;
}
