#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 1000000
ll a[N];
int main(){
	ll n,res;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	res=a[1]-a[0];
	for (int i=2;i<n;i++)
		res=min(res,a[i]-a[i-1]);
	cout<<res;
	return 0;
}
