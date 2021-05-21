#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<long long>());
	cout<<a[0]<<" "<<a[1]<<" "<<a[2];	
	return 0;
}
