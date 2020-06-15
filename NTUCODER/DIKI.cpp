#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,pos=0;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++){
		pos=lower_bound(a+i,a+n,a[i]+m)-a;
		if (a[pos]-a[i]==m){
			cout<<a[i]<<" "<<a[pos];
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
