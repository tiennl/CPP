#include <bits/stdc++.h>
using namespace std;
long long stol(string x){
	long long c=0;
	stringstream str2num(x);
				str2num>>c;
	return c;
}
int main(){
	string s,s1="",s2="";
	long long num1=0,num2=0,vt=0;
	getline(cin,s);
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9'){
			s1+=s[i];
			for (int j=i+1;j<s.size();j++)
				if (s[j]>='0' && s[j]<='9') s1+=s[j];
				else if (s[j]=='-' || s[j]=='_' || s[j]==';' || s[j]=='.' || s[j]==','
					|| s[j]=='/' || s[j]=='|' || s[j]==' '){
					vt=j;
					break;
				}
			break;
		}
	for (int i=vt;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9'){
			s2+=s[i];
			for (int j=i+1;j<s.size();j++)
				if (s[j]>='0' && s[j]<='9') s2+=s[j];
				else break;
			break;
		}
	num1=stol(s1);
	num2=stol(s2);
	cout<<(num2-num1)*1200;
	return 0;
}
