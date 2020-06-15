#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
ll a[N];
int main(){
	FIO
	ll n,m,k,p=0;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			p++;
			a[p]=i*j;
		}
	sort(a+1,a+p+1);
	cout<<a[k];
	return 0;
}
