#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[100000],b[100000];
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		ll sum=0;
		for (int i=0;i<n;i++) cin>>a[i];
		for (int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		for (int i=0;i<n;i++) sum+=a[i]*b[i];
		cout<<sum<<endl;
	}
	return 0;
}
