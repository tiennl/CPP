#include <bits/stdc++.h>
long long a[10000000],vt[10000000],b[10000000];
using namespace std;
void sorta(int l, int r,long long a[], long long vt[]){
	long long pivot=a[(l+r)/2];
	int i=l,j=r;
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
void sortb(int l, int r,long long vt[], long long b[]){
	long long pivot=vt[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (vt[i]<pivot) i++;
		while (vt[j]>pivot) j--;
		if (i<=j){
			swap(b[i],b[j]);
			swap(vt[i],vt[j]);
			i++;
			j--;
		}
	}
    if (l<j) sortb(l,j,vt,b);
    if (r>i) sortb(i,r,vt,b);
}
int main(){
	long long n,m,k=1,muc=0;
	cin>>n;
	for (int i=0;i<2*n;i++) cin>>a[i];
	for (int i=0;i<2*n;i++) vt[i]=i;
	sorta(0,2*n-1,a,vt);
	m=2*n-1;
	b[m]=muc;
	while (m>=0){
		k*=2;
		muc++;
		for (int i=0;i<k;i++){
			m--;
			b[m]=muc;
		} 
	}
	sortb(0,2*n-1,vt,b);
	for (int i=0;i<2*n;i++) cout<<b[i]<<" ";
	return 0;
}
