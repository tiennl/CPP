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

void noAnswer(void) {
    cout << -1 << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   400400
#define LOG   20

int value[MAX], next[MAX], n;
vector<int> pos[MAX];
int rmq[MAX][LOG + 1];
int lg2[MAX];

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);
}

void prepare(void) {
    FOR(i, 1, n) pos[value[i]].push_back(i);

    FOR(i, 1, n) if (pos[i].size() > 1) REP(j, (int)pos[i].size() - 1)
        next[pos[i][j]] = pos[i][j + 1];

    FOR(i, 1, n) rmq[i][0] = next[i];
    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) rmq[i][j] = max(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);
    FOR(i, 1, n) {
        while (MASK(lg2[i]) <= i) lg2[i]++; lg2[i]--;
    }
}

int getMax(int l, int r) {
    assert(l <= r);
    int k = lg2[r - l + 1];
    return max(rmq[l][k], rmq[r - MASK(k) + 1][k]);
}

bool checkFirst(int x) {
    if (pos[x].size() < 2) return false;

    REP(i, pos[x].size() - 1) {
        int l = pos[x][i];
        int r = pos[x][i + 1];
        if (l + 1 > r - 1) continue;

        int tmp = getMax(l + 1, r - 1);
        if (tmp > r) return true;
    }
    return false;
}

int findFirst(void) {
    FOR(i, 1, n) if (checkFirst(i)) return i;
    noAnswer();
}

bool checkSecond(int first, int second) {
    if (first == second) return false;

    vector<int> &pf = pos[first];
    vector<int> &ps = pos[second];

    if (ps.size() < 2) return false;
    if (ps.back() < pf.front()) return false;

    set<int> choices;
    FORE(it, ps) {
        int id = upper_bound(ALL(pf), *it) - pf.begin();
        if (id > 0) {
            choices.insert(id);
            if (choices.size() > 1) return true;
        }
    }
    return choices.size() > 1;
}

int findSecond(int first) {
    FOR(i, 1, n) if (checkSecond(first, i)) return i;
    assert(false);
}

void process(void) {
    int first = findFirst();
    int second = findSecond(first);
    cout << first << " " << second << endl;
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
