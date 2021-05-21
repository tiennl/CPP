#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10000000],s[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,sum=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	s[n]=0;
	for (int i=n-1;i>0;i--) s[i]=s[i+1]+a[i];
	for (int i=0;i<n-1;i++) sum+=a[i]*s[i+1];
	cout<<sum;
	return 0;
}
