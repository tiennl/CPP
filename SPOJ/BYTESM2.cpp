#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
ll a[1005][1005],dp[1005][1005];
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll h,w,res=0;
		for (int i=0;i<105;i++)
			for (int j=0;j<105;j++) a[i][j]=0,dp[i][j]=0;
		cin>>h>>w;
		for (int i=0;i<h;i++)
			for (int j=0;j<w;j++){
				cin>>a[i][j];
				dp[i][j]=a[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
				res=max(res,dp[i][j]);	
			}
		cout<<res<<endl;
	}
	return 0;
}
