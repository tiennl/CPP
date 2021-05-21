#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
	stack <char> s1;
	stack <char> s2;
	string s,res="";
	char t;
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]!='<' && s[i]!='>' && s[i]!='-') s1.push(s[i]);
		if (s[i]=='<' && !s1.empty()){
			t=s1.top();
			s1.pop();
			s2.push(t);
		}
		if (s[i]=='>' && !s2.empty()){
			t=s2.top();
			s2.pop();
			s1.push(t);
		}
		if (s[i]=='-' && !s1.empty())
			s1.pop();
	}
	while (!s1.empty()){
		res+=s1.top();
		s1.pop();
	}
	for (int i=res.size()-1;i>=0;i--) cout<<res[i];
	while (!s2.empty()){
		cout<<s2.top();
		s2.pop();
	}
	return 0;
}
