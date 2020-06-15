#include <iostream>
#include <math.h>
using namespace std;
unsigned long long a[10000000];
unsigned long long b[10000000];
unsigned long long c[10000000];
main(){
	unsigned long long t,k,m,n,s,d,k1;
	int max=0;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>a[i];
		cin>>b[a[i]];
		if (a[i]>max) max=a[i];
	}
	d=0;
	s=0;
	while (d<=max){
		s++;
		if ((s*s-1)%3==0){
			d++;
			k1=b[d];
			if (b[d]==0) c[d]=(s*s-1);
			else
			if (b[d]>0) c[d]=((s%b[d])*(s%b[d])%b[d])-1;
		//	cout<<c[d]<<" "<<b[d]<<endl;
		}
	}
//	for (int i=0;i<max;i++) cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
	for (int i=0;i<t;i++){
		cout<<c[a[i]]%b[a[i]]<<endl;
	}
}
