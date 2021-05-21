#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
long long a[10000000];
long long b[10000000];
void sort(long long l,long long r,long long a[],long long b[]){
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
    if (l<j) sort(l,j,a,b);
    if (r>i) sort(i,r,a,b);
}
main(){
	long long n,d;
	unsigned long long c;
	ifstream fi ("olympic.inp");
	ofstream fo ("olympic.out");
	fi>>n>>c;
	for (long long i=0;i<n;i++) fi>>a[i]>>b[i];
	sort(0,n-1,a,b);
	d=0;
	for (long long i=0;i<n;i++){
	 	if (a[i]<=c){
	 		c+=b[i];
			d++;	
		}
		if (a[i]>c) break;
	}
	fo<<d;
	fi.close();
	fo.close();
}
