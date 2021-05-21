#include <bits/stdc++.h>
using namespace std;
long long a[10000000],vt[10000000];
void sort(int l, int r,long long a[],long long  vt[]){
	int pivot=a[(l+r)/2];
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
    if (l<j) sort(l,j,a,vt);
    if (r>i) sort(i,r,a,vt);
}
int main(){
	int n;
	cin>>n;
	long long m=pow(2,n);
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=m;i++) vt[i]=i;
	sort(1,m,a,vt);
	
	return 0;
}
