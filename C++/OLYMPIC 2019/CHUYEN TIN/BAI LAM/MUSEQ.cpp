#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000

ll a[N],b[N],vt[N];

void sorta(ll l, ll r, ll a[], ll vt[]){
	ll pivot=a[(l+r)/2];
	ll i=l,j=r;
	while (i<j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			swap(vt[i],vt[j]);
			i++;
			j--;
		}
	}
    if (l<j) sorta(l,j,a,vt);
    if (r>i) sorta(i,r,a,vt);
}

void sortvt(ll l, ll r, ll vt[], ll b[]){
	ll pivot=vt[(l+r)/2];
	ll i=l,j=r;
	while (i<j){
		while (vt[i]<pivot) i++;
		while (vt[j]>pivot) j--;
		if (i<=j){
			swap(vt[i],vt[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}
    if (l<j) sortvt(l,j,vt,b);
    if (r>i) sortvt(i,r,vt,b);
}

int main(){
	ll t,n;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n;
		for (int j=0;j<n;j++) cin>>a[j];
		for (int j=0;j<n;j++) vt[j]=j;
		sorta(0,n-1,a,vt);
		b[0]=1;
		for (int j=1;j<n;j++){
			if (a[j]==a[j-1]) b[j]=b[j-1];
			if (a[j-1]<a[j]) b[j]=b[j-1]+1;
		}
		sortvt(0,n-1,vt,b);
		for (int j=0;j<n;j++) cout<<b[j]<<" ";
		cout<<endl;
	}
	return 0;
}
