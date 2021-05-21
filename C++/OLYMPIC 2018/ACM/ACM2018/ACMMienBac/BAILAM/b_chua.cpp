#include <iostream>
using namespace std;
long long a[100000];
long long b[10000000];
main(){
	int n;
	unsigned long long s,min;
	cin>>n;
	s=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
		b[a[i]]++;
	}
	min=s;
	for (int i=0;i<n;i++){
		if (b[a[i]]!=0 && b[a[i]]*a[i]<min) min=b[a[i]]*a[i];
	}
	cout<<s-min;
}
