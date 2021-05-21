#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1005

bool v[N][N];
ll n,m,res=0;

bool check(ll x, ll y){
	return (x>=0 && x<n && y>=0 && y<m);
}

void dfs(ll x, ll y){
	v[x][y]=1;
	if (check(x-1,y) && !v[x-1][y]) dfs(x-1,y);
	if (check(x+1,y) && !v[x+1][y]) dfs(x+1,y);
	if (check(x,y-1) && !v[x][y-1]) dfs(x,y-1);
	if (check(x,y+1) && !v[x][y+1]) dfs(x,y+1);
	return;
}

int main(){
	FIO
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			char c;
			cin>>c;
			if (c=='.') v[i][j]=0;
			else v[i][j]=1;
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (!v[i][j]){
				dfs(i,j);
				res++;
			}
	cout<<res;
	return 0;
}
