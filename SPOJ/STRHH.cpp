#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	string s;
	cin>>t;
	while (t--){
		cin>>s;
		for (int i=0;i<s.size()/2;i+=2) cout<<s[i];
		cout<<endl;
	}
	return 0;
}
