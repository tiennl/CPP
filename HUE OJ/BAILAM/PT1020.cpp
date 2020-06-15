#include <bits/stdc++.h>
long long f[50];
using namespace std;
int main(){
	long long t,n;
	f[0]=2;
	f[1]=1;
	for (int i=2;i<=50;i++) f[i]=f[i-1]+f[i-2];
	cin>>t;
	while (t--){
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}
