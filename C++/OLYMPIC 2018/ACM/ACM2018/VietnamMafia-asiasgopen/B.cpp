#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   1000100
int label[MAX];
vector<int> adj[MAX];
int numNode, numEdge;

void loadGraph(void) {
    scanf("%d%d", &numNode, &numEdge);
    REP(love, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int s) {
    label[s] = 0;
    queue<int> q; q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        FORE(it, adj[u]) if (label[*it] < 0) {
            label[*it] = label[u] ^ 1;
            q.push(*it);
        }
    }
}

void process(void) {
    memset(label, -1, sizeof label);
    int numComp = -1;

    FOR(i, 1, numNode) if (label[i] < 0) {
        numComp++;
        bfs(i);
    }

    bool bipa = true;
    FOR(u, 1, numNode) FORE(it, adj[u]) if (label[u] == label[*it]) bipa = false;

    cout << (bipa ? numComp + 1 : numComp) << endl;
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
