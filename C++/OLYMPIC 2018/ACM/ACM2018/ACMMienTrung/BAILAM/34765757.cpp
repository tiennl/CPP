#include <iostream>
#include <math.h>
using namespace std;
long long a[1000000];
main(){
	long long n,max;
	cin>>n;
	max=0;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			if (abs(a[i]-a[j])+abs(i-j)>max) max=abs(a[i]-a[j])+abs(i-j);
		}
	cout<<max;
}
