#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define N 10000000
ll a[N];
ull s[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,t,x,k,res=0;
	cin>>n>>t;
	for (int i=0;i<n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for (int i=0;i<n;i++){
		x=t+s[i]-a[i];
		k=upper_bound(s,s+n,x)-s;
		k--;
		if (k>=0 && k<n) res+=(k-i+1);
	}
	cout<<res;
	return 0;
}
