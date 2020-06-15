#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	string s;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	n=n-(n/s.size())*s.size();
	for (int i=n;i<s.size();i++) cout<<s[i];
	for (int i=0;i<n;i++) cout<<s[i];
	return 0;
}
