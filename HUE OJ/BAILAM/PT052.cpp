#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,mina,maxa,pmin=0,pmax=0;
	cin>>n>>a[0];
	mina=a[0];
	maxa=a[0];
	for (int i=1;i<n;i++){
		cin>>a[i];
		if (a[i]<mina) mina=a[i],pmin=i;
		if (a[i]>maxa) maxa=a[i],pmax=i;
	}
	cout<<abs(pmin-pmax);
	return 0;
}
