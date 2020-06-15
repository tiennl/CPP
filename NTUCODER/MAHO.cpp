#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	long long n;
	cin>>s>>n;
	for (int i=n-1;i>=0;i--) cout<<s[i];
	for (int i=s.size()-1;i>n-1;i--) cout<<s[i];
	return 0;
}
