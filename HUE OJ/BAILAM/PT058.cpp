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
	cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	return 0;
}