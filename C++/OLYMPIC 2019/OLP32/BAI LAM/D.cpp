#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 10000000
ll x[N],d[N],a[N];
ll n,m,num=0,ok=0,res=0;
void pf(){
	num=0;
	for (int i=1;i<=n;i++) num=num*10+x[i];
	if (num%m==0){
		res=max(res,num);
		ok=1;
	}
}
void hv(ll i){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=a[j];
			d[j]=1;
			if (i==n){
				pf();
			//	if (ok==1) break;
			}
			else hv(i+1);
			d[j]=0;
		}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	hv(1);
	if (ok==0) cout<<-1;
	else cout<<res;
	return 0;
}
