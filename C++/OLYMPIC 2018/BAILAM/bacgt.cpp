#include <iostream>
using namespace std;
main(){
	int p,n,tongthuong;
	cin>>p>>n;
	tongthuong=0;
	while (n>0){
		tongthuong=tongthuong+(n/p);
		n=n/p;
	}
	cout<<tongthuong;
}
