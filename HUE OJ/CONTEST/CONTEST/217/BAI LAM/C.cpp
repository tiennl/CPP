#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if ((abs(a[i])<abs(a[j]))|| (abs(a[i])==abs(a[j]) && a[i]<0 && a[j]>0))
				swap(a[i],a[j]);
	for (int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
