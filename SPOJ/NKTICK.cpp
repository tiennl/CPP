#include <bits/stdc++.h>
long long t[10000000],r[10000000],f[10000000];
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>t[i];
	for (int i=0;i<n-1;i++) cin>>r[i];
	f[0]=t[0];
	f[1]=min(t[0]+t[1],r[0]);
	for (int i=2;i<n;i++)
		f[i]=min(t[i]+f[i-1],r[i-1]+f[i-2]);
	cout<<f[n-1];
	return 0;
}
