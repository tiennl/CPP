#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll n,same=0,res=0;
	string s,t;
	cin>>n>>s>>t;
	for (int i=0;i<s.size();i++){
		same=0;
		ll k=i;
		for (int j=0;j<t.size();j++,k++)
			if (t[j]==s[k]) same++,res=max(res,same);
			else{
				res=max(res,same);
				break;
			}
	}
	cout<<2*n-res;
	return 0;
}
