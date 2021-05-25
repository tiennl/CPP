#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10000];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll t;
	string s;
	cin>>t;
	while (t--){
		ll maxo=0,res=0;
		cin>>s;
		for (int i='a';i<='z';i++) a[i]=0;
		for (int i=0;i<s.size();i++) a[s[i]]++;
		for (int i='a';i<='z';i++)
			if (a[i]>=2){
				if (a[i]%2==0) res+=a[i],a[i]=0;
				else res+=a[i]-1,a[i]=1;
			}
		for (int i='a';i<='z';i++) maxo=max(maxo,a[i]);
		res+=maxo;
		cout<<res<<endl;
	}
	return 0;
}
