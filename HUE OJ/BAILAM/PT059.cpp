#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	for (int i=0;i<n/10;i++) cout<<a[i]<<" ";
	return 0;
}
