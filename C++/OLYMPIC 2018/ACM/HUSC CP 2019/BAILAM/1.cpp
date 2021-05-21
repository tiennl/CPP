#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main(){
	string s,st;
	getline(cin,s);
	getline(cin,st);
	st=" "+st;
	for (int i=0;i<s.size();i++)
		for (int j=0;j<st.size();j++)
			if (s[i]==st[j] && st[j-1]==' '){
				for (int k=j;k<st.size();k++) 
					if (st[k]!=' ') cout<<st[k];
				    else break;
				cout<<" ";
			} 
	return 0;
}
