#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define pll pair<ll,ll>
#define pb push_back
#define N 10005
#define maxN 1e9+5
ll n,m,k,res=0;
vector <pll> a[4][N];
ll d1[N],d2[N],d3[N];
void dijkstra(ll s, ll t, ll d[]){
	priority_queue< pll,vector<pll>,greater<pll> > q;
	for (int i=1;i<=n;i++) d[i]=maxN;
	d[s]=0;
	q.push({s,d[s]});
	while (!q.empty()){
		ll u=q.top().first;
		ll w=q.top().second;
		q.pop();
		if (w!=d[u]) continue;
		for (int i=0;i<a[t][u].size();i++){
			ll v=a[t][u][i].first;
			ll ww=a[t][u][i].second;
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
		ll u,v,wa,ca;
		cin>>u>>v>>wa>>ca;
		a[1][u].pb(pll(v,ca));
		a[2][v].pb(pll(u,wa));
		a[3][v].pb(pll(u,ca));
	}
	dijkstra(1,1,d1);
	dijkstra(k,2,d2);
	dijkstra(n,3,d3);
	res=maxN;
	for (int i=1;i<=n;i++)
		if (d1[i]+d2[i]<60) res=min(res,d1[i]+d3[i]);
	cout<<res;
	return 0;
}
