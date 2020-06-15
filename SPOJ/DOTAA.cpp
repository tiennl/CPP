#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1000 
ll a[N];
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n,m,d;
		bool ok=true;
		cin>>n>>m>>d;
		for (int i=0;i<n;i++) cin>>a[i];
		while (m--){
			sort(a,a+n,greater<ll>());
			a[0]-=d;
			if (a[0]<=0){
				ok=false;
				cout<<"NO"<<endl;
				break;
			}
		}
		if (ok) cout<<"YES"<<endl;
	}
	return 0;
}
