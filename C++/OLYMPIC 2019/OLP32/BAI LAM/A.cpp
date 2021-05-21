#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000000],f[1000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	f[0]=1;
	for (int i=1;i<n;i++)
		if (a[i]==a[i-1]) f[i]=f[i-1]+1;
		else f[i]=1;
	for (int i=0;i<n;i++)
		if (f[i]==1) res++;
	cout<<res;
	return 0;
}

