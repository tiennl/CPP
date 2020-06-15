#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k,pos=0,res=0;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n-1;i++){
		pos=lower_bound(a+i,a+n,a[i]+k)-a;
		if (a[pos]-a[i]==k) res++;
	}
	cout<<res;
	return 0;
}
