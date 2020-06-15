#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 

vector <string> r;

int SS(string a, string b){
	if (a==b) return 0;
	if (a.size()>b.size()) return 1;
	else if (a.size()<b.size()) return 2;
	for (int i=0;i<a.size();i++)
		if (a[i]>b[i]) return 1;
		else if (a[i]<b[i]) return 2; 
}

int main(){
	FIO
	string s,res,num="";
	ll coun=0;
	getline(cin,s);
	s+='a';
	for (int i=0;i<s.size();i++){
		if (s[i]=='0') coun++;
		if (isdigit(s[i])) num+=s[i];
		else if (isdigit(s[i-1]) && !isdigit(s[i])){
			while (num[0]=='0') num.erase(0,1);
			r.push_back(num);
			num="";
		}
	}
	for (int i=0;i<r.size()-1;i++)
		for (int j=i+1;j<r.size();j++) 
			if (SS(r[i],r[j])==2) swap(r[i],r[j]);
	if (r[0]=="" && coun>0) cout<<0;
	else cout<<r[0];
	return 0;
}
