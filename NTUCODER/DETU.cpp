#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long res=0;
	cin>>s;
	s='.'+s;
	for (int i=0;i<s.size()-1;i++)
		if (s[i]=='.' && s[i+1]!='.') res++;
	cout<<res;
	return 0;
}
