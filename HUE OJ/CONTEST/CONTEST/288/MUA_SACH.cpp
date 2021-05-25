#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
#define M 10001

ll n,m;
ll h[N],s[N];
ll f[M][M];

ll dp(ll n, ll m){
	for (int i=0;i<=n;i++) f[i][0]=0;
	for (int j=0;j<=m;j++) f[0][j]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (h[i]<=j) f[i][j]=max(s[i]+f[i-1][j-h[i]],f[i-1][j]);
			else f[i][j]=f[i-1][j];
	return f[n][m];
}

int main(){
	FIO
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>h[i];
	for (int i=1;i<=n;i++) cin>>s[i];
	cout<<dp(n,m);
	return 0;
}
