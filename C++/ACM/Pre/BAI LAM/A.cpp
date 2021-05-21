#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,k,res=1e10;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-k+1;i++){
		ll d1=abs(a[i]);
		ll d2=abs(a[i+k-1]);
		if (a[i]<=0 && a[i+k-1]<=0) res=min(res,d1);
		else if (a[i]>=0 && a[i+k-1]>=0) res=min(res,d2);
		else if (a[i]<0 && a[i+k-1]>0) res=min(res,min(2*d1+d2,2*d2+d1)); 
	}
	cout<<res;
	return 0;
}
