#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000000
ll a[N];
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n,k,res=0;
		cin>>n>>k;
		for (int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		res=a[n-1]-a[0];
		for (int i=0;i<n-k+1;i++)
			res=min(res,a[i+k-1]-a[i]);
		cout<<res<<endl;
	}	
	return 0;
}

