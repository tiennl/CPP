#include <bits/stdc++.h>
using namespace std;
#define ll long long 
string s[1000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>s[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j && s[j].find(s[i])!=-1) res++;
	cout<<res;
	return 0;
}
