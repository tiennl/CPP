#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	ll res=1,coun=1;
	getline(cin,s);
	for (int i=1;i<s.size();i++)
		if (s[i]==s[i-1]) coun++;
		else res=max(res,coun),coun=1;
	res=max(res,coun);
	cout<<res;
	return 0;
}
