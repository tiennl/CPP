#include <iostream>
#include <cstdio>
#include <cstring>

#define int long long
using namespace std;
const int maxn = 1000;
int n;
int dis[maxn+1][maxn+1];
int dp[maxn+1][maxn+1];

int caldp(int x,int y)
{
	if (dp[x][y]!=-1)
		return dp[x][y];
		
	if (x==n || y==n)
		dp[x][y] = 0;
	else
	{
		int m=max(x,y)+1;
		dp[x][y] = min(caldp(m,y)+dis[x][m],caldp(x,m)+dis[y][m]);
	}
	
	return dp[x][y];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			cin >> dis[i][j];
			dp[i][j]=-1;
		}
	
	//memset(dp,-1,sizeof(dp));
	cout << caldp(0,0);
	
	
	return 0;
}
