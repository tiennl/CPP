#include <iostream>
#include <fstream>
long long** aa,** bb,*a,*b;
using namespace std;
main(){
	ifstream fi ("auction.inp");
	ofstream fo ("auction.out");
	long long n,res=0;
	fi>>n;
	a=new long long[n+1];
	b=new long long[n+1];
	aa=new long long*[n+1];
	bb=new long long*[n+1];
	for (int i=0;i<n;i++) aa[i]=new long long[n];
	for (int i=0;i<n;i++) bb[i]=new long long[n];
	for (int i=0;i<n;i++) fi>>a[i];
	for (int i=0;i<n;i++) fi>>b[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			aa[i][j]=a[i]+a[j];
		}
	for (int i=0;i<n-1;i++){
		bb[i][i]=b[i];
		for (int j=i+1;j<n;j++){
			bb[i][j]=min(bb[i][j-1],b[j]);
			res=max(res,min(bb[i][j],aa[i][j]));
		}
	}
	fo<<res;
	fi.close();
	fo.close();
}
