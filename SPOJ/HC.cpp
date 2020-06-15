#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n,coun=0;
		char s[4];
		cin>>n;
		while (n--){
			cin>>s;
			if (!strcmp(s,"lxh")) coun++; 
		}
		if (coun%2==0) cout<<"hhb"<<endl;
		else cout<<"lxh"<<endl;
	}
	return 0;
}
