#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	ll n1=0,n2=0,p=0;
	getline(cin,s);
	s+='a';
	for (int i=0;i<s.size();i++)
		if (isdigit(s[i])) n1=n1*10+(s[i]-'0');
		else if (isdigit(s[i-1]) && !isdigit(s[i])){
			p=i;
			break;
		}
	for (int i=p+1;i<s.size();i++)
		if (isdigit(s[i])) n2=n2*10+(s[i]-'0');
		else if (isdigit(s[i-1]) && !isdigit(s[i])) break;
	cout<<(n2-n1)*1200;
	return 0;
}
