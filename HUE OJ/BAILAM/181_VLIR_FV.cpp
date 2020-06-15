#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long res=0;
	while (getline(cin,s)){
		res=0;
		for (int i=0;i<s.size();i++)
			if (s[i]=='a' || s[i]=='o' || s[i]=='y' || s[i]=='i' || s[i]=='e' || s[i]=='u'
			|| s[i]=='A' || s[i]=='O' || s[i]=='Y' || s[i]=='I' || s[i]=='E' || s[i]=='U')
				res++;
		cout<<res<<endl;
	}
	return 0;
}
