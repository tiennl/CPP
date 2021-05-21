#include <iostream>
#include <math.h>
using namespace std;
main(){
	long long n,m;
	cin>>n;
	m=n;
	int tongcs=0;
	while (m!=0){
		tongcs=tongcs+m%10;
		m=m/10;
	}
	if (n%tongcs==0){
		cout<<"1";
	}
	else {
		cout<<"0";
	}
}
