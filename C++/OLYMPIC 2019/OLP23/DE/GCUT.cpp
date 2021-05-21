/*
    Author: longhoang08
**/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const int base = 1e9 + 7;

int n, k;
vector <int> entryEdge[maxn];
vector <int> edge[maxn];

void readInput()
{
    cin >> n >> k;
    ++k;
    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        entryEdge[u].push_back(v);
        entryEdge[v].push_back(u);
    }
}

namespace BruteForce //subtask 1 (n <= 20)
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

// build edge
bool inCycle[maxn];
bool visited[maxn];
vector <int> vertexs, cycle;
bool dfs(int u, int p)
{
    vertexs.push_back(u);
    visited[u] = true;
    for(int v : entryEdge[u])
    {
        if (v == p) continue;
        if (visited[v])
        {
            while (vertexs.back() != v)
            {
                cycle.push_back(vertexs.back());
                vertexs.pop_back();
            }
            cycle.push_back(v);
            return true;
        }
        if (dfs(v, u))
            return true;
    }
    vertexs.pop_back();
    return false;
}

void buildEdge(int u)
{
    visited[u] = true;
    for(int v : entryEdge[u])
    {
        if (visited[v] || inCycle[v])
            continue;
        edge[u].push_back(v);
        buildEdge(v);
    }
}

void buildEdge()
{
    dfs(1, 0);
    for(int u : cycle)
        inCycle[u] = true;
    for(int i = 1; i <= n; i++)
        visited[i] = false;
    for(int i = 1; i <= n; i++)
    {
        if (!visited[i] && inCycle[i])
            buildEdge(i);
    }
}
// End build edge

void add(long long &a, const long long &b)
{
    a += b;
    if (a >= base)
        a -= base;
}

void sub(long long &a, const long long &b)
{
    a -= b;
    if (a < 0)
        a += base;
}

bool inRange(const int &a, const int &b, const int &c)
{
    return (a >= b && a <= c);
}

long long f[maxn][maxn][2];
long long g[maxn][2];

// dfs and caculate on single tree
void dfs(int u)
{
    for(int v : edge[u])
        dfs(v);
    f[u][0][0] = 1;
    f[u][1][1] = 1;
    for(int v : edge[u])
    {
        for(int i = 0; i <= k; i++)
            for(int j = 0; j <= 1; j++)
            {
                g[i][j] = f[u][i][j];
                f[u][i][j] = 0;
            }
        for(int curGroup = 0; curGroup <= k; curGroup++)
            for(int nextGroup = 0; nextGroup <= k; nextGroup++)
            {
                if (inRange(curGroup + nextGroup, 0, k))
                {
                    add(f[u][curGroup + nextGroup][0], (f[v][nextGroup][1] * g[curGroup][0])%base);
                    add(f[u][curGroup + nextGroup][0], (f[v][nextGroup][0] * g[curGroup][0])%base);
                    add(f[u][curGroup + nextGroup][1], (f[v][nextGroup][0] * g[curGroup][1])%base);
                }
                if (inRange(curGroup + nextGroup - 1, 0, k))
                {
                    add(f[u][curGroup + nextGroup - 1][1], (f[v][nextGroup][1] * g[curGroup][1])%base);
                }
            }
    }
}

long long dp[maxn][maxn][2][2];
long long fdp[maxn][maxn]; // don't delete any vertex in cycle
// Cycle DP
long long dynamicPrograming()
{
    for(int u : cycle)
        dfs(u);
    assert(!cycle.empty());
    int u = cycle[0];
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= 1; j++) dp[0][i][j][j] = f[u][i][j];
    for(int i = 0; i <= k; i++)
        fdp[0][i] = f[u][i][1];
    int sz = cycle.size();
    for(int i = 1; i < sz; i++)
    {
        for(int curGroup = 0; curGroup <= k; curGroup++)
            for(int nextGroup = 0; nextGroup <= k; nextGroup++)
            {
                if (inRange(curGroup + nextGroup, 0, k))
                {
                    for(int j = 0; j < 2; j++)
                    {
                        add(dp[i][curGroup + nextGroup][0][j], (dp[i-1][curGroup][0][j] * f[cycle[i]][nextGroup][0])%base);
                        add(dp[i][curGroup + nextGroup][0][j], (dp[i-1][curGroup][1][j] * f[cycle[i]][nextGroup][0])%base);
                        add(dp[i][curGroup + nextGroup][1][j], (dp[i-1][curGroup][0][j] * f[cycle[i]][nextGroup][1])%base);
                    }
                }
                if (inRange(curGroup + nextGroup - 1, 0, k))
                {
                    for(int j = 0; j < 2; j++)
                        add(dp[i][curGroup + nextGroup - 1][1][j], (dp[i-1][curGroup][1][j] * f[cycle[i]][nextGroup][1])%base);
                    add(fdp[i][curGroup + nextGroup - 1], (fdp[i-1][curGroup] * f[cycle[i]][nextGroup][1])%base);
                }
            }
    }
    long long res = 0;
    add(res, dp[sz-1][k-1][0][0]);
    add(res, dp[sz-1][k-1][0][1]);
    add(res, dp[sz-1][k-1][1][0]);
    add(res, dp[sz-1][k][1][1]);
    sub(res, fdp[sz-1][k]);
    add(res, fdp[sz-1][k-1]);
    return res;
}


int main()
{
    if (fopen("a.txt", "r"))
        freopen("a.txt", "r", stdin);
    readInput();
    buildEdge();
    if (n <= 20) cout << BruteForce::solve();
    else cout << dynamicPrograming();
}
