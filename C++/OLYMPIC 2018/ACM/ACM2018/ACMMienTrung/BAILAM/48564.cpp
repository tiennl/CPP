#include <iostream>
using namespace std;
long long a[1000000];
main(){
	long long n,k,minn;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	minn=(a[n-1]-a[0])*n;
	for (long long i=0;i<n-k+1;i++)
	 	for (long long j=i+k-1;j<n;j++){ cout<<i<<" "<<j<<endl;}
	 /*		if (a[i]<0 && a[j]<0 && (0-a[i]<minn)) minn=0-a[i];
	 		if (a[i]>0 && a[j]>0 && a[j]<minn) minn=a[j];
	 		if (a[i]<0 && a[j]>0 && a[j]-a[i]<minn) minn=a[j]-a[i];
		 }   */
	cout<<minn;
}
