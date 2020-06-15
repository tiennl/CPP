#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s,st="hello";
	ll k=0;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]==st[k]) k++;
	if (k==5) cout<<"YES";
	else cout<<"NO";
	return 0;
}
