#include <bits/stdc++.h>
long long a[100000];
using namespace std;
int main(){
	long long n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	res=a[2]-a[0];
	for (int i=0;i<n-2;i++)
		res=max(res,a[i+2]-a[i]);
	cout<<res;
	return 0;
}
