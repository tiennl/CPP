#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100000]; 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	ll res=0;
	getline(cin,s);
	for (int i=0;i<s.size();i++)
		if (a[s[i]]==0){
			res++;
			a[s[i]]=1;
		}
	cout<<res;
	return 0;
}
