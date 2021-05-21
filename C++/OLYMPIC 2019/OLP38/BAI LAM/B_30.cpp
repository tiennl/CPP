#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 50

ll x[N],d[N],a[N],b[N];
ll n,res=0;

void pf(){
	bool ok=true;
	for (int i=1;i<=n;i++) 
		if (a[x[i]]>b[i]){
			ok=false;
			break;
		}
	if (ok) res++;
}

void permu(ll i){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==n) pf();
			else permu(i+1);
			d[j]=0;
		}
}

int main(){
	FIO
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	permu(1);
	cout<<res;
	return 0;
}
