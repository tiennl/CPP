#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll toNum(string s){
	ll num=0;
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9') num=num*10+(s[i]-'0');
		else return -1;
	return num;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	while (t--){
		string a,b,c,ch;
		ll ta=0,tb=0,tc=0;
		cin>>a>>ch>>b>>ch>>c;
		ta=toNum(a);
		tb=toNum(b);
		tc=toNum(c);
		if (ta==-1) ta=tc-tb;
		else if (tb==-1) tb=tc-ta;
		else tc=ta+tb;
		cout<<ta<<" + "<<tb<<" = "<<tc<<endl;
	}
	return 0;
}
