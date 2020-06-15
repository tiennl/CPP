#include <iostream>
#include <math.h>
using namespace std;
bool snt(int);
bool snt(int a){
	if (a<2){
		return false;
	}
	else if (a>2){
		if (a%2==0){
			return false;
		}
		for (int i=2; i<=sqrt(a); i++){
			if (a%i==0){
				return false;
			}
		}
	}
	return true;
}
main(){
	int n;
	int kt;
	kt=0;
	int s;
	s=0;
	while (kt==0){
		cin>>n;
		if (n%2==0){
			s=s+n;
		}
		if (snt(n)==true){
			kt=1;
		}
	}
	cout<<s;
}
