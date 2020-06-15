#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long res=0;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]=='1'){
			res+=pow(2,s.size()-i-1);
		}
	cout<<res;
	return 0;
}

