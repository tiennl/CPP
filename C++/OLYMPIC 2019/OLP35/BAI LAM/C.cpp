#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005
ll a[N],l[N],r[N];
int main(){
	FIO
	ll n,m,L,R;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	r[1]=1;
	for (int i=2;i<=n;i++)
		if (a[i]<=a[i-1]) r[i]=r[i-1];
		else r[i]=i;
	l[n]=n;
	for (int i=n-1;i>=1;i--)
		if (a[i]<=a[i+1]) l[i]=l[i+1];
		else l[i]=i;
	while (m--){
		cin>>L>>R;
		if (l[L]<r[R]) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
