#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 50005 
ll a[N],f[N];
int main(){
	FIO
	ll n,m;
	cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i];
    f[0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[j]<=i) f[i]=max(f[i],f[i-a[j]]+a[j]);
    cout<<f[n];
	return 0;
}
