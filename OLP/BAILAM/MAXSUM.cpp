#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull long long
#define N 1000005 
ull a[N],l[N],r[N];
int main(){
	FIO
	ull n,res;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	l[0]=a[0];
	for (int i=1;i<n;i++) l[i]=max(l[i-1],a[i]);
	r[n-1]=a[n-1];
	for (int i=n-2;i>=0;i--) r[i]=min(r[i+1],a[i]);
	res=a[0]-a[1]*2-a[2];
	for (int i=1;i<n-1;i++)
	 	res=max(res,l[i-1]-a[i]*2-r[i+1]);
	cout<<res;
	return 0;
}
