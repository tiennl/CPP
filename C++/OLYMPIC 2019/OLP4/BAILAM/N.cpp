#include <bits/stdc++.h>
using namespace std;
double v[100],sum[100];
int main(){
	long long n,a,b;
	double res=0;
	cin>>n>>a>>b;
	for (int i=1;i<=n;i++) cin>>v[i];
	sort(v+1,v+n+1,greater<double>());
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+v[i];
	for (int i=a;i<=b;i++)
		if (sum[i]/i>res) res=sum[i]/i;
	cout<<fixed<<setprecision(6)<<res<<endl;
	return 0;
}

