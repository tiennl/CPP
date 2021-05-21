#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100000];
int main(){
	ll n,res=0;
	string s;
	cin>>n;
	for (int i='a';i<='z';i++) a[i]=0;
	for (int i=1;i<=n;i++){
		cin>>s;
		for (int j=0;j<s.size();j++)
			if (a[s[j]]==i-1) a[s[j]]++;
	}
	for (int i='a';i<='z';i++) 
		if (a[i]==n) res++;
	cout<<res;
	return 0;
}
