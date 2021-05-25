#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10000000];

bool isSquare(ll x){
	ll k=sqrt(x);
	if (k*k==x) return true;
	return false;
} 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,num,res=10000000;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++)
		if (isSquare(a[i])){
			cout<<a[i];
			return 0;
		}
	return 0;
}
