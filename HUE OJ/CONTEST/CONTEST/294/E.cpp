#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

map <char,ll> coun;

int main(){
	FIO
	string s;
	ll res=0;
	getline(cin,s);
	for (int i=0;i<s.size();i++)
		coun[s[i]]++;
	coun['E']/=2;
	res=min(coun['T'],min(coun['E'],coun['N']));
	cout<<res;
	return 0;
}
