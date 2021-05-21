#include <iostream>
using namespace std;
long long a[10000000];
void sort(long long l, long long r,long long a[]){
	int pivot=a[(l+r)/2];
	long long ii=l,jj=r;
	long long tt;
	while (ii<jj){
		while (a[ii]<pivot) ii++;
		while (a[jj]>pivot) jj--;
		if (ii<=jj){
			tt=a[ii];a[ii]=a[jj];a[jj]=tt;
			ii++;
			jj--;
		}
	}
    if (l<jj) sort(l,jj,a);
    if (r>ii) sort(ii,r,a);
}
main(){
	long long n,k,minn,j;
	cin>>n>>k;
	for (long long i=0;i<n;i++) cin>>a[i];
	sort(0,n-1,a);
	minn=2*(a[n-1]-a[0]);
	if (n==1 && k==1){
		if (a[0]>=0) cout<<a[0];
		if (a[0]<0) cout<<0-a[0];
	}
	else{
	for (long long i=0;i<n-k+1;i++){
			j=i+k-1;
	 		if (a[i]<=0 && a[j]<=0 && (0-a[i]<minn)) minn=0-a[i];
	 		if (a[i]>=0 && a[j]>=0 && a[j]<minn) minn=a[j];
	 		if (a[i]<=0 && a[j]>=0){
	 			if (0-a[i]<a[j] && 0-a[i]+a[j]-a[i]<minn) minn=0-a[i]+a[j]-a[i];
	 			if (0-a[i]>=a[j] && a[j]-a[i]+a[j]<minn) minn=a[j]-a[i]+a[j];
			 }
	}   
	cout<<minn;}
}


