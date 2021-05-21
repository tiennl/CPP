#include <iostream>
#include <math.h>
long long a[10000000];
using namespace std;
void sort(int l, int r,long long a[]){
	long long pivot=a[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (a[i]>pivot) i++;
		while (a[j]<pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
    if (l<j) sort(l,j,a);
    if (r>i) sort(i,r,a);
}
int main(){
	int n;
	cin>>n;
	for (int ii=0;ii<n;ii++) cin>>a[ii];
	sort(0,n-1,a);
	for (int ii=0;ii<n;ii++) cout<<a[ii]<<" ";
	return 0;
}
