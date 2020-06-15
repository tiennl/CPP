#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long res=0;
	cin>>s;
	for (int i=0;i<s.size();i++)
		res+=(s[i]-48);
	cout<<res;
	return 0;
}
