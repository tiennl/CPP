#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isOperator(char x){
	if (x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		return true;
	return false;
}
bool isLetter(char x){
	if (x>='a' && x<='z') return true;
	return false;
}
bool isOpen(char x){
	if (x=='(') return true;
	return false;
}
bool isClose(char x){
	if (x==')') return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	string s;
	cin>>t;
	while (t--){
		cin>>s;
		stack <char> a;
		for (int i=0;i<s.size();i++){
			if (isOpen(s[i]) || isOperator(s[i])) a.push(s[i]);
			if (isLetter(s[i])) cout<<s[i];
			if (isClose(s[i])){
				if (isOperator(a.top())){
					cout<<a.top();
					a.pop();
				}
				a.pop();
			}
		}
		cout<<endl;
	}
	return 0;	
}
