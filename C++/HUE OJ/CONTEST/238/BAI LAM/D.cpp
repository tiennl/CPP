#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll res=0,num=0;
	string s;
	getline(cin,s);
	s+=" ";
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9') num=num*10+(s[i]-48);
		else{
			res+=num;
			num=0;
		}
	cout<<res;
	return 0;
}
