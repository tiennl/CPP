#include <iostream>
#include <math.h>
int a[100000];
int b[100000];
using namespace std;
void sort(int l, int r,int a[]){
	int pivot=a[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}
    if (l<j) sort(l,j,a);
    if (r>i) sort(i,r,a);
}
main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++) b[i]=i;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(0,n-1,a);
	if (b[n-2]<b[n-1]) cout<<b[n-2]<<" "<<b[n-1]<<" "<<a[n-2]<<" "<<a[n-1]<<" "<<a[n-2]*b[n-2]+a[n-1]*b[n-1];
	else cout<<b[n-1]<<" "<<b[n-2]<<" "<<a[n-1]<<" "<<a[n-2]<<" "<<a[n-2]*b[n-2]+a[n-1]*b[n-1];
}
