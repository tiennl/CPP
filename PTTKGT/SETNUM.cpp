#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10000005

ll a[N];

int main(){
	FIO
	ll n,res=1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=1;i<n;i++) 
		if (a[i]!=a[i-1]) res++;
	if (n==0) cout<<0;
	else cout<<res;
	return 0;
}
