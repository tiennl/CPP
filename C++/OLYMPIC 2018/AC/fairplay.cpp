#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int a[100000];
int b[100000]; 
int main()
{
	ifstream fi ("fairplay.inp");
	ofstream fo ("fairplay.out");
	int n,d,d1,d2;
	fi>>n;
	for (int i=0;i<n;i++) fi>>a[i];
	for (int i=0;i<n;i++) fi>>b[i];
	sort(a,a+n); 
	sort(b,b+n);
	d=0;
	d1=0;
	d2=0;
	while (d2<n){
		if (b[d2]>a[d1]){
			d++;
			d1++;
			d2++;
		}
		else{
			d2++;
		}
	}
	fo<<d;
	fi.close();
	fo.close();
}
