#include <iostream>
#include <math.h>
using namespace std;
long long a[100000];
void sort(int l, int r,long long a[]){
	int pivot=a[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
    if (l<j) sort(l,j,a);
    if (r>i) sort(i,r,a);
}
main(){
	int n,d;
	unsigned long long s,min;
	cin>>n;
	s=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(0,n-1,a);
	min=s;
	int i=0;
	d=1;
	while (i<n){
		i++;
		if (a[i]==a[i-1]) d++;
		else{
		//	cout<<a[i-1]<<" "<<d<<" "<<min<<endl;
			if (d*a[i-1]<min) min=d*a[i-1];
			d=1;
		}
 	}
	cout<<s-min;
}
	
