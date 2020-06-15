#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	ll num=0,res=1e5;
	getline(cin,s);
	s+='a';
	for (int i=0;i<s.size();i++)
		if (isdigit(s[i])) num=num*10+(s[i]-'0');
		else if (isdigit(s[i-1]) && !isdigit(s[i])){
			res=min(res,num);
			num=0;
		}
	cout<<res;
	return 0;
}
