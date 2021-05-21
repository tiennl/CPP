#include <iostream>
#include <fstream>
using namespace std;
long long a[1000];
long long b[1000];
long long k[1000];
ifstream fi ("scard.inp");
ofstream fo ("scard.out");
main(){
	int m,n,d;
	unsigned long long s,ss;
	fi>>m>>n;
	s=1;
	d=0;
	for (int i=0;i<m;i++){
		fi>>k[i];
		s*=k[i];
	}
	for (int i=0;i<n;i++){
		ss=1;
		for (int j=0;i<m;j++){
			fi>>a[j];
			ss*=a[j];
		}
		if (s%ss==0){
			d++;
			b[d]=i+1;
		}
	}
	fo<<d<<endl;
	for (int i=0;i<d;i++) fo<<b[d]<<" ";
	fi.close();
	fo.close();
}
