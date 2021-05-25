#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cc[10000000],l[10000000],r[10000000];
ll countCC,n,m,res=0;
void newCC(ll x, ll y){
	for (int i=1;i<=n;i++)
		if (cc[i]==y) cc[i]=x;
	for (int i=1;i<=n;i++)
		if (cc[i]==countCC) cc[i]=y;
}
void CC(){
	ll x,y;
	for (int i=1;i<=m;i++)
		if (cc[l[i]]!=cc[r[i]]){
			x=min(cc[l[i]],cc[r[i]]);
			y=max(cc[l[i]],cc[r[i]]);
			newCC(x,y);
			countCC--;
		}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
	for (int i=1;i<=n;i++) cc[i]=i;
	ll countCC=n;
	CC();
	for (int i=1;i<=countCC;i++){
		int pos=0;
		pos=find(cc+1,cc+n,i)-cc;
		if (cc[pos]==i) res++;
	}
	if (res==1) cout<<"Graph is connected";
	else cout<<"Graph is not connected with "<<res<<" connected components";
	return 0;
}
