#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++)
		if (a[i]%2==0) cout<<a[i]<<" ";
	for (int i=0;i<n;i++)
		if (a[i]%2!=0) cout<<a[i]<<" ";
	return 0;
}
