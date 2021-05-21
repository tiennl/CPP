#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll k,n,res=0;
	cin>>k>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i>1) res=max(res,a[i]-a[i-1]);
	}
	res=max(res,a[1]+k-a[n]);
	res=k-res;
	cout<<res;
	return 0;
}
