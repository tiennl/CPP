#include <iostream>
using namespace std;
long long a[1000000];
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
	long long n,k,minn,j;
	cin>>n>>k;
	for (long long i=0;i<n;i++) cin>>a[i];
	sort(0,n-1,a);
	minn=100000000;
	for (long long i=0;i<n-k+1;i++){
			j=i+k-1;
			cout<<i<<" "<<j<<endl;
	 		if (a[i]<=0 && a[j]<=0 && (0-a[i]<minn)) minn=0-a[i];
	 		if (a[i]>=0 && a[j]>=0 && a[j]<minn) minn=a[j];
	 		if (a[i]<=0 && a[j]>=0){
	 			if (0-a[i]<a[j] && 0-a[i]+a[j]-a[i]<minn) minn=0-a[i]+a[j]-a[i];
	 			if (0-a[i]>=a[j] && a[j]-a[i]+a[j]<minn) minn=a[j]-a[i]+a[j];
			 }
	}   
	cout<<minn;
}
