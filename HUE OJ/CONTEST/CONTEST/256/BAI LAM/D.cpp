#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define maxN 1e18
#define N 500
ll dp[N][N]; 
int main(){
	FIO
	ll n,ma,mb,a,b,c,res=maxN;
	cin>>n>>ma>>mb;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++) 
			dp[i][j]=maxN;
	dp[0][0]=0;
	for (int i=0;i<n;i++){
		cin>>a>>b>>c;
		for (int j=N-a;j>=0;j--)
			for (int k=N-b;k>=0;k--){
				if (dp[j][k]==maxN) continue;
				dp[j+a][k+b]=min(dp[j+a][k+b],dp[j][k]+c);
			}
	}
	for (int i=1;;i++)
		if (i*ma<N && i*mb<N)
			res=min(res,dp[i*ma][i*mb]);
		else break;
	if (res==maxN) cout<<-1;
	else cout<<res;
	return 0;
}
