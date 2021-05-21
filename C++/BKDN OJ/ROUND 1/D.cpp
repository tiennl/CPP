#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
vector <ll> graph[N];
ll f0[N];
void solve(vector <ll> graph[], ll V, ll x, ll t){ 
    ll level[V]; 
    bool marked[V]; 
    queue<ll> que; 
    que.push(x); 
    level[x] = 0; 
    marked[x] = true; 
    while (!que.empty()) { 
        x = que.front(); 
        que.pop(); 
        for (int i = 0; i < graph[x].size(); i++) { 
            ll b = graph[x][i]; 
            if (!marked[b]) { 
                que.push(b); 
                level[b] = level[x] + 1; 
                marked[b] = true; 
            } 
        } 
    } 
    for (int i = 0; i < V; i++) level[i]--;
    for (int i = 0; i < V; i++)
    	if (level[i]>t) level[i]=-1;
    	else if (f0[i]==1) level[i]=0;
    for (int i = 1; i < V; i++) cout<<level[i]<<" ";
} 
int main(){
	FIO
	ll n,k,t,m;
	cin>>n>>k>>t;
	for (int i=0;i<k;i++){
		ll num;
		cin>>num;
		f0[num]=1;
		graph[0].push_back(num); 
		graph[num].push_back(0); 
	} 
	cin>>m;
	while (m--){
		ll num1,num2;
		cin>>num1>>num2;
		graph[num1].push_back(num2); 
		graph[num2].push_back(num1); 
	}
    solve(graph,n+1,0,t); 
	return 0;
}
