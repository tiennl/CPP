#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
ll tplt[10000],dau[10000],cuoi[10000];
using namespace std;
void CapNhatTPLT(ll tplt[],ll x, ll y,ll n,ll SoTPLT){
	foru(i,1,n)
		if (tplt[i]==y) tplt[i]=x;
	foru(i,1,n)
		if (tplt[i]==SoTPLT) tplt[i]=y;
}
void TPLT(ll tplt[],ll dau[],ll cuoi[],ll m,ll n,ll SoTPLT){
	ll i,x,y;
	foru(i,1,m)
		if (tplt[dau[i]]!=tplt[cuoi[i]]){
			x=min(tplt[dau[i]],tplt[cuoi[i]]);
			y=max(tplt[dau[i]],tplt[cuoi[i]]);
			CapNhatTPLT(tplt,x,y,n,SoTPLT);
			SoTPLT--;
		}
}
int main(){
	ll n,m;
	cin>>n>>m;
	foru(i,1,m) cin>>dau[i]>>cuoi[i];
	foru(i,1,n) tplt[i]=i;
	ll SoTPLT=n;
	TPLT(tplt,dau,cuoi,m,n,SoTPLT);
	cout<<SoTPLT<<endl;
	foru(i,1,SoTPLT){
		foru(j,1,n)
			if (tplt[j]==i) cout<<j<<" ";
		cout<<i<<" "<<endl;
	}
}
