#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const double INF = 1e4;
const double EPS = 1e-8;

struct Edge
{
    int i, j;
    double c;
    Edge(double c, int i, int j) : c(c), i(i), j(j) {}
};

inline double sqr(double x)
{
    return x * x;
}

inline bool operator < (const Edge& a, const Edge& b)
{
    return a.c + EPS < b.c;
}

double x[MAXN], y[MAXN];
int father[MAXN];

int find(int x)
{
    return father[x] == x ? x : father[x] = find(father[x]);
}

int main()
{
    int n, e, m;
    assert(scanf("%d%d%d", &n, &e, &m) == 3);
    assert(1 <= n && n <= MAXN);
    assert(0 <= m && m <= MAXN);
    assert(1 <= e && e <= n);

    for (int i = 0; i < n; ++ i) {
        assert(scanf("%lf%lf", &x[i], &y[i]) == 2);
        assert(fabs(x[i]) <= INF);
        assert(fabs(y[i]) <= INF);
        if (i < e) {
            father[i] = 0;
        } else {
            father[i] = i;
        }
    }

    for (int i = 0; i < m; ++ i) {
        int a, b;
        assert(scanf("%d%d", &a, &b) == 2);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        -- a;
        -- b;
        father[find(a)] = find(b);
    }

    vector<Edge> edges;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            edges.push_back(Edge(sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])), i, j));
        }
    }
    sort(edges.begin(), edges.end());

    double ret = 0;
    for (const Edge& edge : edges) {
        int fa = find(edge.i), fb = find(edge.j);
// fprintf(stderr, "%d %d %.10f\n", fa, fb, edge.c);
        if (fa != fb) {
            ret += edge.c;
            father[fa] = fb;
        }
    }
    printf("%.3f\n", ret);

    return 0;
}