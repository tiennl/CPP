#include <bits/stdc++.h>
using namespace std;
double a[500];
int main(){
	long long n;
	double sum=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	cout<<fixed<<setprecision(6)<<sum/n<<endl;
	sort(a+1,a+n+1);
	if (n%2==1) cout<<fixed<<setprecision(6)<<a[n/2+1];
	else cout<<fixed<<setprecision(6)<<(a[n/2]+a[n/2+1])/2;
	return 0;
}
