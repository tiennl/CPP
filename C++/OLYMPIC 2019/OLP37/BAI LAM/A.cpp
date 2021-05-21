#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10000005

ll a[N];

bool check(ll x, ll y){
	ll c[11]={0};
	while (x>0){
		c[x%10]++;
		x/=10;
	}
	while (y>0){
		if (c[y%10]>0) return true;
		y/=10;
	}
	return false;
}

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (check(a[i],a[j])) res++;
	cout<<res;
	return 0;
}
