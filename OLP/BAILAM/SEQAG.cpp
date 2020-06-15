#include <fstream>
using namespace std;
long long a[500000];
main(){
	ifstream fi("seqag.inp");
	ofstream fo("seqag.out");
	int n,i,j;
	long long sum=0,min,max;
	fi>>n;
	for (i=0;i<n;i++) fi>>a[i];
	for (i=0;i<n;i++){
		min=a[i];
		max=a[i];
		for (j=i;j<n;j++){
			if (a[j]>max) max=a[j];
			if (a[j]<min) min=a[j];
			sum+=(min*max*(j-i+1));
			sum%=1000000000;
		}
	}
	fo<<sum;
	fi.close();
	fo.close();
	
}
