#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll a[100000];
		ll n,k,res=0;
		cin>>n>>k;
		for (int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n,greater<ll>());
		for (int i=0;i<n;i++){
			if (k<=0) break;
			k-=a[i];
			res++;
		}
		if (k<=0) cout<<res<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
