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

#define MAX   2000227

bool notPrime[MAX];
int cntDiv[MAX];

void prepare(void) {
    FOR(i, 1, MAX - 1) {
        for (int j = i; j < MAX; j += i) cntDiv[j]++;
    }

    REP(i, 2) notPrime[i] = true;
    FOR(i, 1, MAX - 1) if (!notPrime[i]) {
        for (int j = 2 * i; j < MAX; j += i) notPrime[j] = true;
        for (int j = i; j < MAX; j += i) cntDiv[j]--;
    }
}

void process(void) {
    int t; scanf("%d", &t);
    REP(love, t) {
        int x; scanf("%d", &x); assert(x < MAX);
        printf("%d\n", cntDiv[x]);
    }
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
