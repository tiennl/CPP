#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[500000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,q,base=1e9+7;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while (q--){
		ll c,l,r;
		ll mul=1,count=0;
		cin>>c>>l>>r;
		if (c==0) a[l]=r;
		else{
			for (int i=l;i<=r;i++) mul*=a[i]%base;
			for (int i=1;i<=sqrt(mul);i++)
				if (mul%i==0){
					if (i==mul/i) count++;
					else count+=2;
				}
			cout<<count<<endl;
		} 
	}
	return 0;
}
