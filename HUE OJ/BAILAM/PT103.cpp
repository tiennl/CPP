#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N],s[N];

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	s[n]=0;
	for (int i=n-1;i>0;i--) s[i]=s[i+1]+a[i];
	for (int i=0;i<n-1;i++) res+=a[i]*s[i+1];
	cout<<res;
	return 0;
}
