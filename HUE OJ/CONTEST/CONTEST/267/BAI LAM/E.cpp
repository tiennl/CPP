#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll res=0;
		string n;
		cin>>n;
		for (int i=0;i<n.size();i++)
			if ((n[i]-'0')%2==0) res+=(n[i]-'0');
		cout<<res<<endl;
	}
	return 0;
}
