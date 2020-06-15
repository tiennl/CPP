#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	while (t--){
		ll sum=0;
		string s;
		cin>>s;
		for (int i=0;i<s.size();i++) 
			sum+=(s[i]-48);
		cout<<sum<<endl;
	}
	return 0;
}
