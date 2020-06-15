#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,sum=1,coun=0;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	for (int i=0;i<n;i++){
		if (sum>=m) break;
		coun++;
		sum+=a[i]-1;
	}
	if (sum<m) cout<<-1;
	else cout<<coun;
	return 0;
}
