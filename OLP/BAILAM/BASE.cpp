#include <iostream>
using namespace std;
bool doicoso(long long a, int b){
	int du=a%b;
	while (a>0){
		if (a%b!=du) return false;
		a=a/b;
	}
	return true;
}
main(){
	long long x;
	cin>>x;
	int kt;
	kt=0;
	int n=1;
	while (kt==0){
		n++;
		if (doicoso(x,n)==true){
			cout<<n;
			kt=1;
		}
	//	if (n==11){ cout<<"0"; break; }
	}
}
