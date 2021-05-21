#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int oo = 1000000007;

long long sum;
int minC;
vector<vector<int> > adj;
vector<int> c;
vector<bool> visited;
bool haveCycle;

void dfs(int u, int par) {
    visited[u] = true;
    sum += c[u];
    minC = min(minC, c[u]);

    for(int v: adj[u]) {
        if (v == par)
            continue;

        if (!visited[v])
            dfs(v, u);
        else
            haveCycle = true;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    c.resize(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &c[i]);

    vector<pii> e(k);
    for(int i = 0; i < k; ++i) {
        scanf("%d%d", &e[i].first, &e[i].second);
        --e[i].first; --e[i].second;
    }

    vector<int> id(k);
    for(int i = 0; i < k; ++i)
        id[i] = i;

    for(int i = 0; i < k; ++i) {
        int p;
        scanf("%d", &p); --p;

        id.erase(find(id.begin(), id.end(), p));

        adj.assign(n, vector<int>());
        for(int j: id) {
            int u = e[j].first, v = e[j].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.assign(n, false);

        long long ans = 0;

        for(int u = 0; u < n; ++u) {
            if (!visited[u]) {
                haveCycle = false;
                sum = 0;
                minC = oo;

                dfs(u, -1);

                ans += sum;
                if (!haveCycle)
                    ans -= minC;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
