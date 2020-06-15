#include <iostream>
using namespace std;
main(){
	long long a,b,r;
	cin>>a>>b;
	while (b>0){
		r=a%b;
		a=b;
		b=r;
	}
	cout<<a;
}
