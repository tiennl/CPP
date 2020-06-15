#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll n,t,res=0;
	string s1,s2;
	cin>>n>>s1>>s2;
	for (int i=0;i<s1.size();i++){
		t=abs(s1[i]-s2[i]);
		res+=min(t,10-t);
	}
	cout<<res;
	return 0;
}
