#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 300000 
ll a[N],b[N];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,q,x,y;
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	while (q--){
		cin>>x>>y;
		a[x]=y;
		for (int i=1;i<=n;i++) b[i]=a[i];
		sort(b+1,b+n+1);
		cout<<b[(n+1)/2]<<" ";
	}
	return 0;
}
