#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
ll a[N];
int main(){
	FIO
	ll n,m;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	cin>>m;
	while (m--){
		ll num;
		cin>>num;
		cout<<lower_bound(a,a+n,num)-a+1<<" ";
	}
	return 0;
}
