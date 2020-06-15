#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
bool isPalin(string s){
	for (int i=0;i<=s.size()/2;i++)
		if (s[i]!=s[s.size()-i-1]) return false;
	return true;
}
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		string s;
		cin>>s;
		if (isPalin(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
