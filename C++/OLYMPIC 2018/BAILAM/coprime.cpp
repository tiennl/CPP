#include <iostream>
using namespace std;
long long a[100000],b[100000];
bool coprime(long long x, long long y){
	long long r=0;
	while (y>0){
		r=x%y;
		x=y;
		y=r;
	}
	if (x==1) return true;
	return false;
}
main(){
	int n,d=0,max=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		
		for (int j=1;j<n-i+1;j++){
			for (int k=0;k<n;k++) b[k]=a[k];
			for (int k=i;k<i+j;k++) b[k]=-1;
			d=0;
			for (int k=1;k<n;k++) 
				if (b[k]>b[k-1] && coprime(b[k],b[k-1])) d++;
			if (d==n-1 && j+1>max) max=j+1;	
			for (int k=0;k<n;k++) cout<<b[k]<<" ";
			cout<<d<<endl;	
		} 
	}
	cout<<max;
}
