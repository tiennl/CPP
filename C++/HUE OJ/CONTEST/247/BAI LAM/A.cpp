#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
const int N=1000000;
int n,m,k=0,x,y;
vector <bool> used(N,false);
vector <int> s,g[N];
void dfs(int v){
	used[v]=true;
	s.pb(v);
	for (int i:g[v])
		if (!used[i]) dfs(i);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>x>>y;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	for (int i=0;i<n;i++){
		if (!used[i]){
			k++;
			s.clear();
			dfs(i);
		}
	}
	if (k==1) cout<<"Graph is connected";
	else cout<<"Graph is not connected with "<<k<<" connected components";
	return 0;
}
