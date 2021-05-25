#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 500
ll x[N],y[N],p[N];
ll n;
void solve(ll j, bool a[]){
	a[j]=true;
	double d=0;
	for (int i=0;i<n;i++){
		if (a[i]) continue;
		d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		if (d<=p[j]) solve(i,a);
	}
}
int main(){
	FIO
	ll res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>x[i]>>y[i]>>p[i];
	for (int i=0;i<n;i++){
		bool a[N]={false};
		solve(i,a);
		ll coun=0;
		for (int j=0;j<n;j++)
			if (a[j]) coun++;
		res=max(res,coun);
	}	
	cout<<res;	
	return 0;
}
