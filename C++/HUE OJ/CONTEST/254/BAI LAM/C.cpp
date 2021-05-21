#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1005
#define maxN 1e9
ll a[N],b[N],c[N];
ll d[N][N],e[N][N];
int main(){
	FIO
	ll n,m,res=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			d[i][j]=maxN;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		d[a[i]][b[i]]=c[i];
		d[b[i]][a[i]]=c[i];
		e[a[i]][b[i]]=c[i];
		e[b[i]][a[i]]=c[i];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	for (int i=1;i<=m;i++)
		if (d[a[i]][b[i]]<e[a[i]][b[i]]) res++;
	cout<<res;
	return 0;
}
