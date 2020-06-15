#include <bits/stdc++.h>
long long f[1000000];
using namespace std;
int main(){
	long long n;
	cin>>n;
	f[1]=f[2]=1;
	for (int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	for (int i=1;i<=n;i++) cout<<f[i]<<" ";
	return 0;
}
