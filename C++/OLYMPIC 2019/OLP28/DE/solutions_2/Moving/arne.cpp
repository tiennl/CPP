#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 50000;

struct edge {
    int a, b, t;
    bool operator<(const edge& e) const { return a < e.a; }
} edges[2 * MAX];

int N, visits[MAX], start[MAX], freq[MAX], best0[MAX], *best1;
long long ttime[MAX], best;

void init() {
    for (int i = 0; i < N - 1; ++i) {
        edges[N - 1 + i].a = --edges[i].b;
        edges[N - 1 + i].b = --edges[i].a;
        edges[N - 1 + i].t = edges[i].t;
    }
    
    sort(edges, edges + 2 * (N - 1));
    fill(start, start + N, 2 * (N - 1));
    for (int i = 0; i < 2 * (N - 1); ++i) if (i == 0 || edges[i].a != edges[i - 1].a) start[edges[i].a] = i;
}

void dfs1(int m, int up) {
    ttime[m] = 0;
    freq[m] = visits[m];
    for (int i = start[m]; i < 2 * (N - 1) && edges[i].a == m; ++i) if (edges[i].b != up) {
        dfs1(edges[i].b, m);
        ttime[m] += ttime[edges[i].b] + 2ll * freq[edges[i].b] * edges[i].t;
        freq[m] += freq[edges[i].b];
    }
}

void dfs2(int m, int up, int f, long long t) {
    if (t + ttime[m] < best) best = t + ttime[m], best1 = best0;
    if (t + ttime[m] == best) *best1++ = m;
    for (int i = start[m]; i < 2 * (N - 1) && edges[i].a == m; ++i) if (edges[i].b != up) {
        dfs2(edges[i].b, m, f + freq[m] - freq[edges[i].b],
                t + ttime[m]
                - ttime[edges[i].b] - 2ll * freq[edges[i].b] * edges[i].t
                + 2ll * (f + freq[m] - freq[edges[i].b]) * edges[i].t);
    }
}

int main() {
    int t, u;

    for (cin >> t; t > 0; --t) {
        cin >> N;
        for (int i = 0; i < N - 1; ++i) cin >> edges[i].a >> edges[i].b >> edges[i].t;
        cin >> u;
        memset(visits, 0, N * sizeof visits[0]);
        for (int i = u; i > 0; --i) {
            cin >> u;
            cin >> visits[--u];
        }

        init();
        dfs1(0, 0);
        best = 112233445566778899ll;
        best1 = best0;
        dfs2(0, 0, 0, 0);

        sort(best0, best1);
        cout << best << endl;
        for (int *p = best0; p != best1; ++p) {
            cout << *p + 1;
            if (p + 1 != best1) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
