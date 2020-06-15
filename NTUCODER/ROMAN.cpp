#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll a[1000];
int main(){
	FIO
	ll res=0;
	string s;
	a['I']=1;
	a['V']=5;
	a['X']=10;
	a['L']=50;
   	a['C']=100;
   	a['D']=500;
   	a['M']=1000;
   	cin>>s;
   	for (int i=0;i<s.size();i++)
   		if (a[s[i]]>=a[s[i+1]]) res+=a[s[i]];
   		else res-=a[s[i]];
   	res+=a[s[s.size()]];
   	cout<<res;
	return 0;
}
