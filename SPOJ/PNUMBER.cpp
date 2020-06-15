#include <iostream>
#include <math.h>
using namespace std;
bool snt(long long);
bool snt(long long a){
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
	long long x,y;
	cin>>x>>y;
	for (int j=x;j<=y;j++){
		if (snt(j)==true) cout<<j<<endl;
	}
}
