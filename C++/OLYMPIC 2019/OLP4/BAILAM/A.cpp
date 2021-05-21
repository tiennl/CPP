#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (i==5 || i==13) cout<<" ";
		else cout<<s[i];
	return 0;
}
