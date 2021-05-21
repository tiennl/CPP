#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
main(){
	unsigned long long t,k,m,n,s,d,k1;
	int max=0;
	ifstream fi ("n3s.inp");
	ofstream fo ("n3s.out");
	fi>>t;
	for (int i=0;i<t;i++){
		fi>>k>>m;
		n=(k-1)+(k-1)/2+1;
		fo<<((n%m)*(n%m))%m-1<<endl;
	}
	fi.close();
	fo.close();
}

