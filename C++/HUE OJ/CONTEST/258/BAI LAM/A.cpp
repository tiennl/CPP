#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1000000 
ll a[N],b[N];
int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i]>>b[i];
	for (int i=n-1;i>=0;i--){
		a[i]+=res;
		if (a[i]%b[i]!=0)
			res+=b[i]-a[i]%b[i];
//		a[i]+=b[i]-a[i]%b[i];
	}
	cout<<res;
//	cout<<endl;for (int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
