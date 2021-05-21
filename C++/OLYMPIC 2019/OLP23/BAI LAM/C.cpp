#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int base = 1e9 + 7;

int n, k;
vector <int> entryEdge[maxn];

namespace BruteForce
{
    bool deleted[maxn];
    bool visited[maxn];
    int res = 0;

    void dfs(int u)
    {
        visited[u] = true;
        for(int v : entryEdge[u])
            if (!deleted[v] && !visited[v])
                dfs(v);
    }

    bool calc()
    {
        for(int i = 1; i <= n; i++)
            visited[i] = false;
        int cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            if (!deleted[i] && !visited[i])
            {
                dfs(i);
                ++cnt;
            }
            if (cnt > k) break;
        }
        return cnt == k;
    }

    void Try(int i)
    {
        for(int j = 0; j < 2; j++)
        {
            deleted[i] = j;
            if (i == n)
            {
                res += calc();
            }
            else Try(i+1);
        }
    }

    int solve()
    {
        Try(1);
        return res;
    }
}

int main()
{
    if (fopen("a.txt", "r"))
    {
        freopen("a.txt", "r", stdin);
    }
    cin >> n >> k;
    ++k;
    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        entryEdge[u].push_back(v);
        entryEdge[v].push_back(u);
    }
    cout << BruteForce::solve() << endl;
}
