#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
bool isOpen(char c){
	if (c=='(' || c=='[' || c=='{') return true;
	else return false;
}
bool isClose(char c){
	if (c==')' || c==']' || c=='}') return true;
	else return false;
}
bool isMatch(char x, char y){
	if (x=='{' && y=='}') return true;
	if (x=='[' && y==']') return true;
	if (x=='{' && y=='}') return true;
	return false;
}
bool ParenMatch(string x){
	stack <char> s;
	char Token;
	for (int i=0;i<x.size();i++){
		if (isOpen(x[i])) s.push(x[i]);
		else if (isClose(x[i])){
			if (s.empty()) return false;
			Token=s.top();
			s.pop();
			if (!isMatch(Token,x[i])) return false;
		}
	}
	return (s.empty());
}
int main(){
	string st;
	cin>>st;
	if (ParenMatch(st)) cout<<"TRUE";
	else cout<<"FALSE";
	return 0;
}
