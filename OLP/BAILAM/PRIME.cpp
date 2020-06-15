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
	cin>>n;
	if (snt(n)==true){
		cout<<"TRUE";
	}
	else{
		cout<<"FALSE";
	}
}
