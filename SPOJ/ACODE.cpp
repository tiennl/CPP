#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[5001];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	while (cin>>s){
		if (s[0]=='0') return 0;
		dp[0]=dp[1]=1;
		for (int i=2;i<=s.size();i++){
			dp[i]=0;
			char c1=s[i-2]-'0', c2=s[i-1]-'0';
			if (c1==1 || (c1==2 && c2<=6)) dp[i]+=dp[i-2];
			if (c2!=0) dp[i]+=dp[i-1];
		}
		cout<<dp[s.size()]<<endl;
	}
	return 0;
}
