#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
bool Xaungoac(string st){
	stack <char> s;
	for (int i=0;i<st.size();i++){
		if (st[i]=='(')
			s.push(st[i]);
		else{
			if (!s.empty()){
				if (st[i]==')')
					if (s.top()!='(') return false;
				s.pop();
			}
			else return false;
		}
	}
	if (!s.empty()) return false;
	return true;
}
int main(){
	string st;
	cin>>st;
	if (Xaungoac(st)) cout<<"TRUE";
	else cout<<"FALSE";
	return 0;
}
