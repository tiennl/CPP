#include <iostream>
using namespace std;
unsigned long long giaithua(long long x){
	if (x==0) return 1;
	unsigned long long s=1;
	for (long long i=1;i<=x;i++) s*=i;
	return s;
}
main(){
	long long n;
	cin>>n;
	cout<<n<<"! = "<<giaithua(n);
}
