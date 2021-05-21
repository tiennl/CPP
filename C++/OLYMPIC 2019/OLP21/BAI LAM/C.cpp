#include <bits/stdc++.h>
long long a[5000000];
using namespace std;
int main(){
	long long n;
	unsigned long long res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]>0) res+=(2*a[i]);
	}
	cout<<res;
	return 0;
}
