#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 30001
ll a[N][31],p[31],f[N*31],s[31];
int n,m,k,res,t,j;
char c;
ll solve(int x, int l, int r){
	return a[x][r]-a[x][l-1]*p[r-l+1];
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=30;j++){
			cin>>c;
			if (c=='A') a[i][j]=0;
			if (c=='C') a[i][j]=1;
			if (c=='G') a[i][j]=2;
			if (c=='T') a[i][j]=3;
		}
	}
	p[0]=1;
	for (int i=1;i<=30;i++) p[i]=p[i-1]*4;
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=30;j++)
			a[i][j]=a[i][j-1]*4+a[i][j];
	res=-1;
	for (int l=30;l>=1;l--){
		m=0;
		for (int x=1;x<=n;x++){
			t=0;
			s[0]=-1;
			for (int i=1;i<=31-l;i++){
				j=i+l-1;
				t++;
				s[t]=solve(x,i,j);
			}
			sort(s+1,s+t+1);
			for (int i=1;i<=t;i++)
				if (s[i]!=s[i-1]) m++,f[m]=s[i];
				
		}
		sort(f+1,f+m+1);
		ll count=0;
		for (int i=1;i<=m;i++){
			if (f[i]==f[i-1]) count++;
			else count=1;
			if (count>=k){
				res=l;
				break;
			}
		}
		if (res!=-1) break;
	}
	cout<<res;
	return 0;
}
