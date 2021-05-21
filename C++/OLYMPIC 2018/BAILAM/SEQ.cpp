#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 200005

ll a[N],f[N],g[N],m1[N],m2[N];

int main(){
	FIO
	ll n,res;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	f[0]=0;
	f[1]=0;
	for (int i=2;i<n;i++) f[i]=max(a[i]+a[i-1]+a[i-2],f[i-3]+a[i]+a[i-1]+a[i-2]);
	g[n-1]=0;
	g[n-2]=0;
	for (int i=n-3;i>=2;i--) g[i]=max(a[i]+a[i+1]+a[i+2],g[i+3]+a[i]+a[i+1]+a[i+2]);
	m1[0]=-1e9;
	m1[1]=-1e9;
	for (int i=2;i<n;i++) m1[i]=max(f[i],m1[i-1]);
	m2[n-1]=-1e9;
	m2[n-2]=-1e9;
	for (int i=n-3;i>=0;i--) m2[i]=max(g[i],m2[i+1]);
	res=a[0]+a[1]+a[2]+a[3]+a[4]+a[5];
	for (int i=3;i<n-1;i++) res=max(res,m1[i]+m2[i+1]);
	cout<<res;
	return 0;
}
