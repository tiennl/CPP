#include <iostream>
using namespace std;
main(){
	int kt;
	long long n,luythua,k,mu,p;
	cin>>n>>p;
	kt=0;
	k=0;
	mu=0;
	luythua=1;
	while (kt==0){
		mu++;
		luythua=luythua*p;
		if ((n%luythua)==0) k=mu;
		if (luythua>n){
			kt=1;
			break;
		}
	}
	cout<<k;
}
