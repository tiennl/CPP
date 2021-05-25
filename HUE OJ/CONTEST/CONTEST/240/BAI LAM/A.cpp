#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000];
bool isPrime(ll x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	for (int i=0;i<n;i++)
		if (isPrime(a[i])){
			cout<<a[i];
			return 0;
		}
	return 0;
}
