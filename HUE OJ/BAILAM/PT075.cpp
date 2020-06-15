#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define pb push_back
#define N 1000005

vector <string> res;

bool isChar(char c){
	if ((c>='a' && c<='z') || (c>='A' && c<='Z')) return true;
	return false;
}

int main(){
	FIO
	string s,st="";
	ll rmax=0;
	getline(cin,s);
	s=" "+s+" ";
	for (int i=0;i<s.size()-1;i++)
		if (isChar(s[i]) && isChar(s[i+1])) st+=s[i];
		else if (isChar(s[i]) && !isChar(s[i+1])){
			st+=s[i];
			rmax=max(rmax,(ll)st.size());
			res.pb(st);
			st="";
		}
	cout<<rmax<<endl<<res.size();	
	return 0;
}
