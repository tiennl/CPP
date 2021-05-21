#include <bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
ll tplt[100000],dau[100000],cuoi[100000],dau1[100000],cuoi1[100000];
using namespace std;
void CapNhatTPLT(ll tplt[],ll x, ll y,ll n,ll SoTPLT){
	foru(i,1,n)
		if (tplt[i]==y) tplt[i]=x;
	foru(i,1,n)
		if (tplt[i]==SoTPLT) tplt[i]=y;
}
void TPLT(ll tplt[],ll dau[],ll cuoi[],ll m,ll n,ll &SoTPLT){
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
	ll n,m,k,l,r;
	cin>>n>>m;
	foru(i,1,m) cin>>dau1[i]>>cuoi1[i];
	cin>>k;
	foru (i,1,k){
		foru (i,1,m) dau[i]=dau1[i],cuoi[i]=cuoi1[i];
		cin>>l>>r;
		foru (i,l,r) dau[i]=0,cuoi[i]=0;
		foru(i,1,n) tplt[i]=i;
		ll SoTPLT=n;
		TPLT(tplt,dau,cuoi,m,n,SoTPLT);
		cout<<SoTPLT<<endl;
	}
	return 0;
}
/*
6 5
1 2
5 4
2 3
3 1
3 6
6
1 3
2 5
1 5
5 5
2 4
3 3 
*/
