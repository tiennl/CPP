#include <bits/stdc++.h>
using namespace std;
double a[300000],sum[300000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n;
	double s1=0,s2=0,s=0,maxx=0,res1=0,res2=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	for (int i=1;i<=n-1;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		s1=(double)i/n*100;
		s2=sum[i]/s*100;
		if (s2-s1>maxx){
			maxx=abs(s1-s2);
			res1=s1;
			res2=s2;
		}
	}
	cout<<fixed<<setprecision(6)<<res1<<endl<<res2;
	return 0;
}
