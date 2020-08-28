#include <iostream>
using namespace std;
int ucln(int x,int y){
	int r;
	while (y>0){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
main(){
	int n1,n2;
	cin>>n1>>n2;
	cout<<n1*n2/ucln(n1,n2);
}
