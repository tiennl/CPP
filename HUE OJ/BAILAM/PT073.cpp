#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	string s;
	ll n=0,res=0;
	for (int i='a';i<='z';i++) a[i]=0;
	while (cin>>s){
		n++;
		for (int i=0;i<s.size();i++) 
			if (a[s[i]]==n-1) a[s[i]]++;
	}
	for (int i='a';i<='z';i++)
		if (a[i]==n) res++;
	cout<<res;
 	return 0;
}
