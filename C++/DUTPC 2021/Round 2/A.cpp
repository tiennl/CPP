#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1005

ll a[N][N],res[N][N];
ll mod=1e9+7;

int main(){
	FIO
	ll n,m;
	char x;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			cin>>x;
			if (x=='#') a[i][j]=1;
			else a[i][j]=0;
		}
	if (a[0][0]==0) res[0][0]=1;
	for (int i=1;i<n;i++)
		if (a[i][0]==0) res[i][0]=res[i-1][0];
	for (int i=1;i<m;i++)
		if (a[0][i]==0) res[0][i]=res[0][i-1];
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			if (a[i][j]==0) res[i][j]=(res[i-1][j]+res[i][j-1])%mod;
	cout<<res[n-1][m-1];
	return 0;
}
