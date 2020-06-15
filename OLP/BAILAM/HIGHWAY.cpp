#include <iostream> 
#include <algorithm>
#include <fstream>
int a[1000000];
using namespace std;
main(){
	ifstream fi ("highway.inp");
	ofstream fo ("highway.out");
	int n,min;
	fi>>n;
	for (int i=0;i<n;i++) fi>>a[i];
	sort(a,a+n);
	min=a[1]-a[0];
	for (int i=2;i<n;i++){
		if (a[i]-a[i-1]<min) min=a[i]-a[i-1];
	}
	fo<<min;
	fi.close();
	fo.close();
}
