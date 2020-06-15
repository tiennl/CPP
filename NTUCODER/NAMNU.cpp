#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,nam=0,nu=0;
	string s;
	cin>>n>>m;
	cin>>s;
	if (s.size()>2) s+=s[0];	
	for (int i=0;i<s.size()-1;i++)
		if (s[i]==s[i+1]){
			if (s[i]=='0') nu++;
			else nam++;
		}
	cout<<abs(nam-nu);
	return 0;
}
