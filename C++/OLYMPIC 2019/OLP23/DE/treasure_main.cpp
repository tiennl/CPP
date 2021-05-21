#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> pset;
vector<int> minC;
vector<bool> haveCycle;

long long sum;

int init(int n, vector<int> c) {
    pset.resize(n);
    for(int i = 0; i < n; ++i)
        pset[i] = i;

    minC = c;

    haveCycle.assign(n, false);
}

int findSet(int i) {
    return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
}

void unionSet(int u, int v) {
    int p = findSet(u), q = findSet(v);
    if (p == q) {
        if (!haveCycle[p]) {
            haveCycle[p] = true;
            sum += minC[p];
        }
        return;
    }

    sum += haveCycle[p] ? 0 : minC[p];
    sum += haveCycle[q] ? 0 : minC[q];

    pset[q] = p;
    minC[p] = min(minC[p], minC[q]);
    haveCycle[p] = haveCycle[p] | haveCycle[q];

    sum -= haveCycle[p] ? 0 : minC[p];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> c(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &c[i]);

    vector<pii> e(k);
    for(int i = 0; i < k; ++i) {
        scanf("%d%d", &e[i].first, &e[i].second);
        --e[i].first; --e[i].second;
    }

    vector<int> p(k);
    for(int i = 0; i < k; ++i) {
        scanf("%d", &p[i]);
        --p[i];
    }

    init(n, c);

    vector<long long> ans(k);
    for(int i = k-1; i >= 0; --i) {
        ans[i] = sum;
        unionSet(e[p[i]].first, e[p[i]].second);
    }

    for(int i = 0; i < k; ++i)
        printf("%lld\n", ans[i]);

    return 0;
}
