#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	string s;
	ll res=0;
	getline(cin,s);
	for (int i='a';i<='z';i++) a[i]=0,a[i-32]=0;
	for (int i=0;i<s.size();i++) a[s[i]]++;
	for (int i='a';i<='z';i++)
		if (a[i]>0 || a[i-32]>0) res++;
	cout<<res;
	return 0;
}
