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
	for (int i=1;i<=n;i++) cin>>a[i];
	while (q--){
		ll l,r,val,p;
		cin>>l>>r>>val;
		p=lower_bound(a+l,a+r+1,val)-a;
		if (p>=l && p<=r) cout<<a[p]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
