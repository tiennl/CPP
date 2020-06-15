#include <iostream>
using namespace std;
int a[1000];
main(){
	int n,k,max=0;
	long long s=0;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		s=0;
		for (int j=i;j<n;j++){
			s+=a[j];
			if (s%k==0)
				if (j-i+1>max) max=j-i+1;
		}
	}
	cout<<max;	
}
