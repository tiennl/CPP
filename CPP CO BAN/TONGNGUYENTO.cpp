#include <iostream>
#include <math.h>
using namespace std;
bool snt(int x){
	if (x<2) return false;
	if (x==2) return true;
	if (x>2){
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0){
			return false;
			break;
		}
	return true;
    }
}
main(){
	int n;
	long long s=0;
	cin>>n;
	for (int j=0;j<n;j++)
		if (snt(j)==true) s+=j;
	cout<<s;
}
