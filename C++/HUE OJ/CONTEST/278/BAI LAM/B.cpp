#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10005

ll n,s=0,res;
ll a[N],x[N];

void nghiem(ll k, ll &res){
	ll s1=0,s2=0;
	for (int i=1;i<=k;i++) s1+=a[x[i]];
	s2=s-s1;
	res=min(res,abs(s1-s2));
}

void tohop(ll i, ll k, ll &res){
	for (int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if (i==k) nghiem(k,res);
		else tohop(i+1,k,res);
	}
}

int main(){
	FIO
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	res=s;
	for (int k=1;k<n;k++) tohop(1,k,res);
	cout<<res;
	return 0;
}
