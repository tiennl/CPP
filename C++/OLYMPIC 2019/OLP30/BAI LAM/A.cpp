#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[100000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n,k;
	cin>>t;
	while (t--){
		cin>>n>>k;
		for (int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n,greater<ll>());
		bool ok=0;
		for (int i=1;i<n;i++) 
			if (a[i]<a[0]) k-=(a[0]-a[i]);
		if (k%n==0 && k>=0) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}
