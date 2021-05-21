#include <fstream>
#include <algorithm>
using namespace std;
long long a[5000];
long long b[5000];
long long c[5000];
main(){
	ifstream fi("tg.inp");
	ofstream fo("tg.out");
	int n,i,j,k;
	long long dem=0;
	fi>>n;
	for (i=0;i<n;i++) fi>>a[i];
	for (i=0;i<n;i++) fi>>b[i];
	for (i=0;i<n;i++) fi>>c[i];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			for (k=0;k<n;k++)
				if (a[i]+b[j]>c[k] && b[j]+c[k]>a[i] && a[i]+c[k]>b[j] &&
				abs(a[i]-b[j])<c[k] && abs(b[j]-c[k])<a[i] && abs(a[i]-c[k])<b[j]) dem++;
	fo<<dem;
	fi.close();
	fo.close();
				
}
