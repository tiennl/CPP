#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long 
#define N 10005

ll a[N][N];

int main(){
	FIO
	ull n,m,q,num=0,res=0,mod=1e9+7;
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			num++;
			a[i][j]=num;
		}	
	while (q--){
		string s;
		ull x,y;
		cin>>s>>x>>y;
		if (s=="R")
			for (int i=1;i<=m;i++) a[x][i]=(a[x][i]*y)%mod;
		else if (s=="S")
			for (int i=1;i<=n;i++) a[i][x]=(a[i][x]*y)%mod;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			res+=a[i][j];
			if (res>mod) res%=mod;
		}
	cout<<res%mod;
	return 0;
}
