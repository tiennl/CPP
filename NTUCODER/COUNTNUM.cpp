#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	ll coun=0;
	getline(cin,s);
	s+=" ";
	for (int i=0;i<s.size()-1;i++)
		if (isdigit(s[i]) && s[i+1]==' ') coun++;
	cout<<coun;
	return 0;
}
