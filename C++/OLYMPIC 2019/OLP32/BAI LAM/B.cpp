#include <bits/stdc++.h>
using namespace std;
#define ll long long 
string maxst(string x, string y){
	while (x[0]=='0') x.erase(0,1);
	while (y[0]=='0') y.erase(0,1);
	if (x==y) return x;
	if (x.size()>y.size()) return x;
	else if (x.size()<y.size()) return y;
	for (int i=0;i<x.size();i++)
		if (x[i]>y[i]) return x;
		else if (x[i]<y[i]) return y;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s,res,num="";
	int ok=0;
	getline(cin,s);
	s+='a';
	for (int i=0;i<s.size();i++){
		if (isdigit(s[i])) num+=s[i];
		else{
			res=maxst(res,num);
			num="";
		}
		if (s[i]=='0') ok=1;
	}
	if (res=="" && ok==1) cout<<0;
	else cout<<res;
	return 0;
}
