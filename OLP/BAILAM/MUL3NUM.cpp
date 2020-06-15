#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000000
ll a[N],b[N]={0};
ll max3(ll a[], ll n){
	ll lmin[N]={-1},rmin[N]={-1},lmax[N]={-1},rmax[N]={-1};
	ll resmax=-N;
	ll smax=a[0],smin=a[0];
	for (int i=1;i<n;i++){
		lmax[i]=smax;
		smax=max(smax,a[i]);
		lmin[i]=smin;
		smin=min(smin,a[i]);
	}
	smax=a[n-1];
	smin=a[n-1];
	for (int i=n-2;i>=0;i--){
		rmax[i]=smax;
		smax=max(smax,a[i]);
		rmin[i]=smin;
		smin=min(smin,a[i]);
	}
	ll max1,max2;
	for (int i=1;i<n-1;i++){
		max1=max(a[i]*lmax[i]*rmax[i],a[i]*lmin[i]*rmin[i]);
		max2=max(a[i]*lmax[i]*rmin[i],a[i]*lmin[i]*rmax[i]);
		resmax=max(resmax,max(max1,max2));
	}
	return resmax;
}
int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	
	return 0;
}
