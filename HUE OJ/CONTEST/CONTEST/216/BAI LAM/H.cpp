#include <bits/stdc++.h>
long long f[10000000],check[1000000000];
using namespace std;
int main(){
	long long n,t;
	f[0]=0;
	f[1]=1;
	for (int i=2;i<=50;i++)	f[i]=f[i-1]+f[i-2];
	check[0]=1;
	for (int i=1;i<=50;i++)
		for (int j=i;j<=50;j++) check[f[i]*f[j]]=1;
	cin>>t;
	while (t--){
		cin>>n;
		if (check[n]==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
