#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
vector<int> graph[N]; 
void printLevels(vector<int> graph[], int V, int x){ 
    int level[V]; 
    bool marked[V]; 
    queue<int> que; 
    que.push(x); 
    level[x] = 0; 
    marked[x] = true; 
    while (!que.empty()) { 
        x = que.front(); 
        que.pop(); 
        for (int i = 0; i < graph[x].size(); i++) { 
            int b = graph[x][i]; 
            if (!marked[b]) { 
                que.push(b); 
                level[b] = level[x] + 1; 
                marked[b] = true; 
            } 
        } 
    } 
    cout << "Nodes"
         << "    "
         << "Level" << endl; 
    for (int i = 0; i < V; i++) 
        cout << " " << i << "   -->   " << level[i] << endl; 
} 
int main(){
	FIO
//	ll n,k,t,m;
//	cin>>n>>k>>t;
//	for (int i=0;i<k;i++){
//		ll num;
//		cin>>num;
//		graph[0].push_back(num); 
//	} 
//	cin>>m;
//	while (m--){
//		ll num1,num2;
//		if (num1>num2) swap(num1,num2);
//		graph[num1].push_back(num2); 
//	}
	int V = 8; 
    vector<int> graph[V]; 
  
    graph[0].push_back(1); 
    graph[1].push_back(0); 
    graph[0].push_back(2); 
    graph[2].push_back(0); 
    
    
    graph[1].push_back(2); 
    graph[2].push_back(1); 
    graph[2].push_back(4); 
    graph[4].push_back(2); 
    graph[2].push_back(5); 
    graph[5].push_back(2); 
    graph[5].push_back(6); 
    graph[6].push_back(5); 
    graph[6].push_back(3); 
    graph[3].push_back(6); 
    
    graph[1].push_back(3); 
    graph[3].push_back(1); 
    printLevels(graph, V, 0); 
	return 0;
}
