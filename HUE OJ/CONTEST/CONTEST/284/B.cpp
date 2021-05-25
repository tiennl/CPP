#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll t[N];

int main(){
	FIO
	ll n,d=1,tmax;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>t[i];
	tmax=max(t[1],t[3]);
	for (int i=2;i<=n-2;i++)
		if (max(t[i],t[i+2])<tmax){
			d=i;
			tmax=max(t[i],t[i+2]);
		}
	cout<<d<<" "<<tmax;
	return 0;
}
