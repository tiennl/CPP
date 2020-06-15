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
	f[0]=2;
	f[1]=1;
	for (int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];
	for (int i=0;i<=n;i++) cout<<f[i]<<" ";
	return 0;
}
