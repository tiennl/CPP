#include <fstream>
#include <algorithm>
using namespace std;
int a[10000];
main(){
	ifstream fi("mmax.inp");
	ofstream fo("mmax.out");
	int n,i;
	long long max;
	fi>>n;
	for (i=0;i<n;i++) fi>>a[i];
	sort(a,a+n);
	max=0;
	max=a[n-1]*a[n-2];	
	if (a[n-1]*a[n-2]*a[n-3]>max) max=a[n-1]*a[n-2]*a[n-3];
	if (a[0]*a[1]>max) max=a[0]*a[1];
	if (a[0]*a[1]*a[n-1]>max) max=a[0]*a[1]*a[n-1];
	fo<<max;
	fi.close();
	fo.close();
}
