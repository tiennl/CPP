#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

map <string,ll> coun;

int main(){
	FIO
	string s,st="";
	getline(cin,s);
	s+=" ";
	for (int i=0;i<s.size();i++)
		if (s[i]==' '){
			coun[st]++;
			if (coun[st]>1){
				cout<<"no";
				return 0;
			}
			st="";
		}
		else st+=s[i];
	cout<<"yes";
	return 0;
}
