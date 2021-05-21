#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000],x[40],n,sum=0,res1=0,res2=0;
void pf(ll x[]){
	ll s=0;
	for (int i=1;i<=n;i++) 
		if (x[i]==1) s+=a[i-1];
	if (abs((sum-s)-s)==res1) res2++;
}
void hv(ll i){
	for (int j=1;j<=2;j++){
		x[i]=j;
		if (i==n) pf(x);
		else hv(i+1);
	}
}
ll minDiff(ll a[], ll i, ll sx, ll sum){
	if (i==0) return abs((sum-sx)-sx);
	return min(minDiff(a,i-1,sx+a[i-1],sum),minDiff(a,i-1,sx,sum));
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	res1=minDiff(a,n,0,sum);
	hv(1);
	cout<<res1<<" "<<res2/2;
	return 0;
}
