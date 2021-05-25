#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	res=a[n-1]*a[n-2]*a[n-3];
	res=max(res,a[0]*a[1]*a[n-1]);
	cout<<res;
	return 0;
}
