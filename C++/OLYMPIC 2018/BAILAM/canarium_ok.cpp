#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
main(){
	ifstream fi ("canarium.inp");
	ofstream fo ("canarium.out");
	int t;
	unsigned long long k,m,n,v1,v2,min;
	v1=0;
	v2=0;
	min=1000000000000;
	fi>>t;
	for (int i=0;i<t;i++){
		fi>>k;
		min=1000000000000;
		v1=0;
		v2=0;
		for (long long m=1;m<=sqrt(k);m++){
			n=(2*k-m-1)/(2*m+1);
			if ((n*m+(n+1)*(m+1)==2*k) && (m<=n) && (n-m<min)){
					min=n-m;
					v1=m;
					v2=n;
			}
		}
		if (v1!=0 && v2!=0) fo<<v1<<" "<<v2<<endl;
		else fo<<"-1 -1"<<endl;
	}
	fi.close();
	fo.close();
}
