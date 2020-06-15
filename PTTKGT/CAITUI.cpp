#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1000005
#define M 10001

ll n,m;
ll w[N],v[N];
ll f[M][M];

ll bag(ll i, ll m){
	if (i==0) return 0;
	if (w[i]>m) return bag(i-1,m);
	else return max(bag(i-1,m),bag(i-1,m-w[i])+v[i]);
}

ll bagDP(ll n, ll m){
	for (int i=0;i<=n;i++) f[i][0]=0;
	for (int j=0;j<=m;j++) f[0][j]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (w[i]<=j) f[i][j]=max(v[i]+f[i-1][j-w[i]],f[i-1][j]);
			else f[i][j]=f[i-1][j];
	return f[n][m];
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
	cout<<bag(n,m)<<endl;
	cout<<bagDP(n,m);
	return 0;
}

/*
10 45
7 3
9 2
5 3
8 1 
9 3
5 2
6 3
7 1
6 3
5 1
*/
