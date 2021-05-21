#include <iostream>
using namespace std;
int a[100];
main(){
	int n,max;
	cin>>n;
	max=0;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-2;i++)
		for (int j=i+1;j<n-1;j++)
			for (int k=j+1;k<n;k++)
				if (a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[i]+a[k]>a[j])
					if (a[i]+a[j]+a[k]>max) max=a[i]+a[j]+a[k];
	cout<<max;
}
