#include <iostream>
#include <cstdlib>
using namespace std;
long long a[1000000];
int main(){
	long long n,maxx,minn,v1,v2,v,m,kq;
 	cin>>n;
	maxx=0;
	for (long long i=0;i<n;i++){
		cin>>a[i];
		if (i==0) minn=a[0];
		if (a[i]>maxx){maxx=a[i];v1=i;}
		if (a[i]<minn){minn=a[i];v2=i;}
	}
	v1++;
	v2++;
	kq=abs(minn-maxx)+abs(v1-v2);
	if (abs(a[0]-a[n-1])+n-1>kq) kq=abs(a[0]-a[n-1])+n-1;
	cout<<kq;
	return 0;
}
