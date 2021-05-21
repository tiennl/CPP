#include <iostream>
#include <fstream>
using namespace std;
long long a[1000];
main(){
	int n,d;
	ifstream fi ("fibseq.inp");
	ofstream fo ("fibseq.out");
	fi>>n;
	d=0;
	if (n<3) fo<<"0";
	else{
		fi>>a[0]>>a[1];
		for (int i=2;i<n;i++){
			fi>>a[i];
			if (a[i]!=a[i-1]+a[i-2]){
				fo<<"0";
				d=1;
				break;
			}}
		if (d==0) fo<<"1";
	}
	fi.close();
	fo.close();
}

