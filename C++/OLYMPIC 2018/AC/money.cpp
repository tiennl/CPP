#include <iostream>
#include <fstream>
using namespace std;
long long a[1000];
main(){
	ifstream fi ("money.inp");
	ofstream fo ("money.out");
	long long m,k,d;
	unsigned long long t;
	fi>>m>>k;
	for (int i=0;i<k;i++) fi>>a[i];
	t=0;
	d=0;
	for (int i=0;i<k;i++){
		t+=a[i];
		if (t>=m){
			t=t-(t/m)*m;
			d++;
		}
	}
	fo<<d;
	fi.close();
	fo.close();
}
