#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	ll num=0,res=1000;
	getline(cin,s);
	s+=" ";
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9') num=num*10+(s[i]-'0');
		else if (!(s[i]>='0' && s[i]<='9') && (s[i-1]>='0' && s[i-1]<='9')){
			res=min(res,num);	
			num=0;
		}
	cout<<res;
	return 0;
}
