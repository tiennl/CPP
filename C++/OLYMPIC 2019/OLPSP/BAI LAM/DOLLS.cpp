#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1000000
ll a[N],b[N]; 
int main(){
	FIO
	ll n,k,m=0,res=0;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<ll>());
	b[0]=a[0];
	res=a[0];
	for (int i=1;i<n;i++){
		int ok=0;
		for (int j=0;j<=m;j++)
			if (b[j]-a[i]>=k){
				ok=1;
				b[j]=a[i];
				break;
			}
		if (ok==0){
			m++;
			b[m]=a[i];
			res+=a[i];
		}
	}
	cout<<res;
	return 0;
}
