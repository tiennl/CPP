#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll f[N];

int main(){
	FIO
	ll n;
	cin>>n;
	f[1]=1;
	for (int i=2;i<=n;i++)
		if (i%2==0) f[i]=i+f[i-1];
		else f[i]=2*i+f[i-1];
	cout<<f[n];
	return 0;
}
