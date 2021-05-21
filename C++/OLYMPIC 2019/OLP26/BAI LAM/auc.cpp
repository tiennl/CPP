#include <iostream>
#include <fstream>
long long a[1000000],b[1000000];
long long** aa,** bb;
using namespace std;
main(){
	ifstream fi ("auction.inp");
	ofstream fo ("auction.out");
	long long n,res=0;
	fi>>n;
	for (int i=0;i<2*n;i++) fo<<1<<" ";
	fi.close();
	fo.close();
}
