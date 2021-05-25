#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000
ll cc[N],l[N],r[N],fl[N],fr[N];
ll countCC,n,m,k,f,s,res=0;
void newCC(ll x, ll y){
	for (int i=1;i<=n;i++)
		if (cc[i]==y) cc[i]=x;
	for (int i=1;i<=n;i++)
		if (cc[i]==countCC) cc[i]=y;
}
void CC(ll &countCC){
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
	for (int i=1;i<=m;i++) cin>>fl[i]>>fr[i];
	cin>>k;
	while (k--){
		for (int i=1;i<=m;i++) l[i]=fl[i],r[i]=fr[i];
		cin>>f>>s;
		for (int i=f;i<=s;i++) l[i]=0,r[i]=0;
		for (int i=1;i<=n;i++) cc[i]=i;
		ll countCC=n;
		CC(countCC);
		cout<<countCC<<endl;
	}
	return 0;
}
