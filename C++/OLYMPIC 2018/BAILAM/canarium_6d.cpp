#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
main(){
	ifstream fi ("canarium.inp");
	ofstream fo ("canarium.out");
	int t;
	long long k,m,n,v1,v2,min;
	v1=0;
	v2=0;
	min=100000000;
	fi>>t;
	for (int i=0;i<t;i++){
		fi>>k;
		min=100000000;
		v1=0;
		v2=0;
		for (int m=1;m<=k;m++)
			for (int n=m;n<=k;n++)
				if ((n*m+(n+1)*(m+1)==2*k) && (n-m<min)){
					min=n-m;
					v1=m;
					v2=n;
			}
		if (v1!=0 && v2!=0) fo<<v1<<" "<<v2<<endl;
		else fo<<"-1 -1"<<endl;
	}
	fi.close();
	fo.close();
}
