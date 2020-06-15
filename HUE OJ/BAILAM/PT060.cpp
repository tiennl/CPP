#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

double a[N];

int main(){
	FIO
	ll n,t;
	double res=0;	
	cin>>n>>t;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<double>());
	for (int i=0;i<t;i++) res+=a[i];
	cout<<fixed<<setprecision(1)<<res;
	return 0;
}
