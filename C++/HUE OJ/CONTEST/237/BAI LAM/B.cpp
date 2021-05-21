#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	a[1]=0;
	for (int i=2;i<=n;i++){
		a[i]=1+a[i-1];
		if (i%2==0) a[i]=min(a[i],1+a[i/2]);
		if (i%3==0) a[i]=min(a[i],1+a[i/3]);
	}
	cout<<a[n];
	return 0;
}
