// C++ program to find the connected component 
// with maximum number of edges 
#include <bits/stdc++.h> 
using namespace std; 
  
// DFS function 
int dfs(int s, vector<int> adj[], vector<bool> visited, 
                                             int nodes) 
{ 
    // Adding all the edges connected to the vertex 
    int adjListSize = adj[s].size(); 
    visited[s] = true; 
    for (long int i = 0; i < adj[s].size(); i++) { 
        if (visited[adj[s][i]] == false) { 
            adjListSize += dfs(adj[s][i], adj, visited, nodes); 
        } 
    } 
    return adjListSize; 
} 
  
int maxEdges(vector<int> adj[], int nodes) 
{ 
    int res = INT_MIN; 
    vector<bool> visited(nodes, false); 
    for (long int i = 1; i <= nodes; i++) { 
        if (visited[i] == false) { 
            int adjListSize = dfs(i, adj, visited, nodes); 
            res = max(res, adjListSize/2); 
        }       
    } 
    return res; 
} 
  
// Driver code 
int main() 
{ 
    int nodes = 6; 
    vector<int> adj[nodes+1]; 
  
    // Edge from vertex 1 to vertex 2 
    adj[1].push_back(2); 
    adj[2].push_back(1); 
  
    adj[2].push_back(3); 
    adj[3].push_back(2); 
    
  	adj[3].push_back(4); 
    adj[4].push_back(3); 
     adj[4].push_back(5); 
    adj[5].push_back(4); 
  	adj[5].push_back(6); 
    adj[6].push_back(5);
    cout << maxEdges(adj, nodes); 
  
    return 0; 
} 
