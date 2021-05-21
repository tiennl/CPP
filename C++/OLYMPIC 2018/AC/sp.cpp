#include <iostream>
#include <fstream>
using namespace std;
main(){
	long long m,n,t,but,tien,dem;
	ifstream fi ("sp.inp");
	ofstream fo ("sp.out");
	fi>>m>>n>>t;
	but=0;
	tien=0;
	dem=0;
	while (but<n){
        ++but;
        ++dem;
		tien=tien+t;
		if (dem==m){
			++but;
			dem=0;
		}
	}
	fo<<tien;
	fi.close();
	fo.close();
}


