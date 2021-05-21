#include <iostream>
using namespace std;
int b[100000];
unsigned long long sum[100000];
main(){
	int n;
	unsigned long long kq;
	cin>>n;
	kq=0;
	for (int i=0;i<n;i++) cin>>b[i];
	sum[n-1]=b[n-1];
	for (int i=n-1;i>=0;i--) sum[i]=sum[i+1]+b[i];
	for (int i=0;i<n-1;i++) kq=kq+b[i]*sum[i+1];
	for (int i=0;i<n;i++) cout<<b[i]<<" "<<sum[i]<<endl;
	cout<<kq;
}
