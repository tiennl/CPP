#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,q;
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>a[i];
	while (q--){
		ll x,l,r,coun=0,res=-1;
		ll s[n]={0};
		cin>>x>>l>>r;
		for (int i=l-1;i<=r-1;i++)
			if (__gcd(x,a[i])>1) res=max(res,a[i]);
		for (int i=l-1;i<=r-1;i++)
			if (a[i]==res) coun++;
		if (coun>0 && res>0) cout<<res<<" "<<coun<<endl;
		else cout<<"-1 -1"<<endl;
	}
	return 0;
}
