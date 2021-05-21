#include <iostream>
#include <math.h>
using namespace std;
bool snt(int);
bool snt(int x){
	if (x<2){
		return false;
	}
	else if (x>2){
		if (x%2==0){
			return false;
		}
		for (int i=2; i<=sqrt(x); i++){
			if (x%i==0){
				return false;
			}
		}
	}
	return true;
}
bool doixung(int x){
	int s=0;
	int temp=x;
	while (x!=0){
		s=s*10+(x%10);
		x=x/10;
	}
	if (s==temp){
		return true;
	}
	return false;
}
main(){
	int a,b,dem;
	cin>>a>>b;
	dem=0;
	for (int i=a;i<=b;i++){
		if ((snt(i)==true) && (doixung(i)==true)){
			++dem;
		}
	}
	cout<<dem;
}
