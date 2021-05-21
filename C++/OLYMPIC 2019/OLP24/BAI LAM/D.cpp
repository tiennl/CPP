#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,k=2,mul=0;
	cin>>n;
/*	a[1]=1;
	a[2]=3;
	for (int i=3;i<n+2;i++) a[i]=2*a[i-1]-a[i-2]+2;
	mul=a[n]*a[n+1];
	while (a[k-1]<mul){
		k++;
		a[k]=2*a[k-1]-a[k-2]+2;
		if (a[k]==mul){
			cout<<k;
			return 0;
		}
	}*/
	cout<<n*n+1;
	return 0;
}
