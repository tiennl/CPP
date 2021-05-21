#include <iostream>
using namespace std;
long long a[1000000];
int main(){
	long long n,maxx,minn,v1,v2,v,m;
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
	if (v1<v2) v=v2-v1;else v=v1-v2;
	if (minn-maxx<0) m=0-(minn-maxx);else m=minn-maxx;
	cout<<m+v<<endl;
	return 0;
}
