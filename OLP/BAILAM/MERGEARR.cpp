#include <iostream>
#include <math.h>
using namespace std;
int a[50000];
int b[50000];
int c[100000];
main(){
	int m,n,k,min,max;
	cin>>m>>n;
	k=0;
	for (int i=0;i<m;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	cout<<(m+n)<<endl;
	int i=0;int j=0;
	while ((i<m) && (j<n)){
		if (a[i]<b[j]){
			c[k]=a[i];
			++i;
		}
		else{
			c[k]=b[j];
			j++;
		}
		++k;	
	}
	for (int i=0;i<k;i++){
		cout<<c[i]<<" ";
	}
		if (i<m){
		for (int ii=i;ii<m;ii++) cout<<a[ii]<<" ";
	}
	else{
		if (j<n){
			for (int ii=j;ii<n;j++) cout<<a[ii]<" ";
		}
	}
}

