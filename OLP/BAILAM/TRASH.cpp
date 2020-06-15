#include <iostream>
#include <fstream>
using namespace std;
long long a[10000000];
unsigned long long s[1000000];
main(){
	ifstream fi ("trash.inp");
	ofstream fo ("trash.out");
	long long n,t,d,k;
	fi>>n>>t;
	d=0;
	for (int i=0;i<n;i++){
		fi>>a[i];
		if (a[i]<=t) d++;
		s[i]=s[i-1]+a[i];
	}
	k=1;
	while (k<n-1){
		k++;
		if (s[k-1]<=t) d++;
		for (int i=0;i<n-k;i++)
			if (s[i+k]-s[i]<=t) d++;
	}
	fo<<d;
	fi.close();
	fo.close();
}
