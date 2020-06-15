#include <bits/stdc++.h>
long long a[1000000];
using namespace std;
int main(){
	long long n,x;
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++)
		if (x>=a[i] && x<=a[i+1]){
			cout<<i;
			return 0;
		}
	if (x>=a[n-1]) cout<<n;
	else cout<<0;
	return 0;
}
