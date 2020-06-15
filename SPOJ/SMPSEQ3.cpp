#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll s[100000],q[100000],am[100000],duong[100000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m;
	cin>>n;
	for (int i=0;i<n;i++) cin>>s[i];
	cin>>m;
	for (int i=0;i<m;i++){
		cin>>q[i];
		if (q[i]>=0) duong[q[i]]=-1;
		else am[abs(q[i])]=-1;
	}
	for (int i=0;i<n;i++) 
		if (s[i]>=0){
			if (duong[s[i]]==0) cout<<s[i]<<" ";
		}
		else if (am[abs(s[i])]==0) cout<<s[i]<<" ";
	return 0;
}
