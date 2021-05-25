#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define pll pair<ll,ll>
#define pb push_back
#define N 10005
#define maxN 1e9+5

ll n,m,k,res=maxN;
vector <pll> a[4][N];
ll d1[N],d2[N],d3[N];

void solve(ll p, ll t, ll d[]){
	priority_queue < pll,vector<pll>,greater<pll> > q;
	for (int i=1;i<=n;i++) d[i]=maxN;
	d[p]=0;
	q.push({p,d[p]});
	while (!q.empty()){
		ll u,v,w,ww;
		u=q.top().first;
		w=q.top().second;
		q.pop();
		if (w!=d[u]) continue;
		for (int i=0;i<a[t][u].size();i++){
			v=a[t][u][i].first;
			ww=a[t][u][i].second; 
			if (d[v]>w+ww){
				d[v]=w+ww;
				q.push({v,d[v]});
			}
		}
	}
}

int main(){
	FIO
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		ll u,v,w,c;
		cin>>u>>v>>w>>c;
		a[1][u].pb({v,c});
		a[2][v].pb({u,w});
		a[3][v].pb({u,c});
	}
	solve(1,1,d1);
	solve(k,2,d2);
	solve(n,3,d3);
	for (int i=1;i<=n;i++)
		if (d1[i]+d2[i]<60) 
			res=min(res,d1[i]+d3[i]);
	cout<<res;
	return 0;
}
