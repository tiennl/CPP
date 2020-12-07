#include <iostream>
#include <math.h>
using namespace std;
bool snt(int a){
	if (a<2) return false;
	for (int i=2;i<=sqrt(a);i++)
		if (a%i==0) return false;
	return true;
}
int main(){
	int n;
	cin>>n;
	if (snt(n)==true) cout<<"true";
	else cout<<"false";
	return 0;
}
