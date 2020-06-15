#include <iostream>
using namespace std;
long long a[400000];
main(){
	int n,d;
	long long k,s;
	cin>>n>>k;
	d=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]==k) d++;
	}
	for (int i=0;i<n-1;i++){
		s=a[i];
		for (int j=i+1;j<n;j++){
			s+=a[j];
			if (s==k) d++;
		}
	}
	cout<<d;
}
