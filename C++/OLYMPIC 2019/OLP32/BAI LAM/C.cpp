#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000000
ll a[N],s[N]; 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	if (n>=1) s[0]=a[0];
	if (n>=2) s[1]=a[0]+a[1];
	if (n>2){
		s[2]=max(a[0]+a[2],a[1]+a[2]);
		s[2]=max(s[2],s[1]);
	}
	for (int i=3;i<n;i++){
		s[i]=max(s[i-1],s[i-2]+a[i]);
		s[i]=max(s[i],s[i-3]+a[i-1]+a[i]);
	}
	cout<<s[n-1];
	return 0;
}
