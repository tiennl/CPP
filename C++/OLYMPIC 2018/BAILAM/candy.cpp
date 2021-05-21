#include <iostream>
#include <math.h>
long long s[200000];
long long a[200000];
using namespace std;
main(){
	int n,k;
	 long long res,min,an,binh,chenh;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	min=s[n-1];
	for (int k=0;k<n;k++){
		an=s[k];
		binh=s[n-1]-s[k];
		if (an-binh>=0) chenh=an-binh;
		else chenh=binh-an;
		if (chenh<min){
			min=chenh;
		}
	}
	cout<<min;
}
