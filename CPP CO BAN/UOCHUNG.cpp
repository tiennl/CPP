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
	int a,b;
	cin>>a>>b;
	cout<<"Uoc chung lon nhat: "<<ucln(a,b);
}
