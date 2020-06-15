#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll n,m;
	while (cin>>n>>m){
		if (n==0 && m==0) return 0;
		ll a[n],b[m];
		for (int i=0;i<n;i++) cin>>a[i];
		for (int i=0;i<m;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+m);
		if (a[0]<b[1]) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}
