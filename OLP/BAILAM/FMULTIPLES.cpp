#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	ll res=0;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]=='4' || s[i]=='8' || s[i]=='0') res++;
	for (int i=0;i<s.size()-1;i++){
		ll num=(s[i]-'0')*10+(s[i+1]-'0');
		if (num%4==0) res+=i+1;
	}
	cout<<res;
	return 0;
}
