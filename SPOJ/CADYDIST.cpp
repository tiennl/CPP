#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005
ll a[N],b[N];
int main(){
	FIO
	ll n;
	while (cin>>n){
		if (n==0) return 0;
		ll res=0;
		for (int i=0;i<n;i++) cin>>a[i];
		for (int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n,greater<ll>());
		for (int i=0;i<n;i++) res+=a[i]*b[i];
		cout<<res<<endl;
	}
	return 0;
}

