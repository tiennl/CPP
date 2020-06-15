#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N],f[N];

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	f[0]=1;
	for (int i=1;i<n;i++) {
		if (a[i]>=a[i-1]) f[i]=f[i-1]+1;
		else f[i]=1;
		res=max(res,f[i]);
	}
	if (n==0) cout<<0;
	else cout<<res;
	return 0;
}
