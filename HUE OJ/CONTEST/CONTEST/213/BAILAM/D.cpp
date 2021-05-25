#include <bits/stdc++.h>
long long a[1000000],sum[1000000];
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	unsigned long long n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=n-1;i>=0;i--) sum[i]=sum[i+1]+a[i];
	for (int i=0;i<n-1;i++) res+=a[i]*sum[i+1];
	cout<<res;
	return 0;
}
