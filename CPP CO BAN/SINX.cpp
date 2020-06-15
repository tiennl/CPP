#include<iostream>
#include <iomanip>
using namespace std;
main(){
	double x,epsilon,sinx,so;
	cin>>x>>epsilon;
	int k=1;
	double so_hang_k=x;
	sinx=so_hang_k;
	while(so_hang_k>=epsilon){
		k++;
		so=2*k-1;
		so_hang_k=(so_hang_k*x*x)/so/(so-1);
		if (k%2==0) sinx-=so_hang_k;
		else sinx+=so_hang_k;
	}
	cout<<fixed<<setprecision(4);
	cout<<sinx<<endl;
	return 0;
}

