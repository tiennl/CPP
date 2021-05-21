#include <iostream>
using namespace std;
long long a[100000000];
main(){
	long long n;
	unsigned long long s;
	cin>>n;
	a[1]=1;
	a[2]=1;
	s=2;
	if (n==1 || n==2) cout<<n;
	else{
	for (long long i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
		s+=a[i];
	}
	cout<<s%13;}
}
//1 1 2 3 5  8  13 21 34
//1 2 4 7 12 20 33 54 88
