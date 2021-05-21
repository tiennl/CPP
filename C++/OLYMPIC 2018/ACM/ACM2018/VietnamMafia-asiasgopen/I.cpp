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

const long long INF = (long long)1e16 + 7LL;

#define SUM(x, y) ((x) + (y) > INF ? INF : (x) + (y))
#define PRODUCT(x, y) ((x) == 0 || (y) == 0 ? 0 : ( INF / (x) > (y) ? 1LL * (x) * (y) : INF ) )
#define ADD(x, y) x = SUM(x, y)

#define CHAR   26
#define LEVEL   60
#define LENGTH   1111111
string trans[CHAR + 3], input;
int transCount[CHAR + 3][CHAR + 3];
long long transLength[CHAR + 3][LEVEL + 3], level;
long long totalTransLength[LENGTH];

void init(void) {
    cin >> input;
    REP(i, CHAR) cin >> trans[i];
    cin >> level;

    REP(i, CHAR) FORE(jt, trans[i]) transCount[i][*jt - 'a']++;
}

vector<long long> transfer(vector<long long> cnt) {
    vector<long long> res(CHAR, 0);
    REP(i, CHAR) REP(j, CHAR) ADD(res[j], PRODUCT(cnt[i], transCount[i][j]));
    return res;
}

long long sumVector(const vector<long long> &cnt) {
    long long res = 0;
    FORE(it, cnt) ADD(res, *it);
    return res;
}

#define LOG   60
char getFirstChar(char c, long long level) {
    int jump[CHAR][LOG + 1];
    memset(jump, 0, sizeof jump);
    REP(i, CHAR) jump[i][0] = trans[i][0] - 'a';
    FOR(j, 1, LOG) REP(i, CHAR) jump[i][j] = jump[jump[i][j - 1]][j - 1];

    int res = c - 'a';
    FORD(i, LOG, 0) if (BIT(level, i)) res = jump[res][i];
    return res + 'a';
}

void reduceLevel(void) {
    if (level <= LEVEL) return;

    char c = getFirstChar(input[0], level - LEVEL);
    input = string(1, c);
    level = LEVEL;
}

void prepareTransLength(void) {
    REP(c, CHAR) {
        vector<long long> cnt(CHAR, 0);
        cnt[c] = 1;

        transLength[c][0] = 1;
        FOR(lv, 1, level) {
            cnt = transfer(cnt);
            transLength[c][lv] = sumVector(cnt);
        }
    }

    REP(i, input.size()) totalTransLength[i + 1] = totalTransLength[i] + transLength[input[i] - 'a'][level];
}

char getChar(char c, int level, long long pos) {
//    printf("finding %c, lv %d, pos %lld\n", c, level, pos);
    if (level == 0) return c;
    if (level == 1) {
        assert(pos <= trans[c - 'a'].size());
        return trans[c - 'a'][pos - 1];
    }

    long long sum = 0;
    FORE(it, trans[c - 'a']) {
        long long more = transLength[*it - 'a'][level - 1];
        if (SUM(sum, more) >= pos) return getChar(*it, level - 1, pos - sum);
        else ADD(sum, more);
    }
    assert(false);
}

long long answer(long long pos) {
    assert(pos <= totalTransLength[input.size()]);
    int tmp = lower_bound(totalTransLength + 1, totalTransLength + input.size() + 1, pos) - totalTransLength;
    pos -= totalTransLength[tmp - 1];
    return getChar(input[tmp - 1], level, pos);
}

void process(void) {
    int q; cin >> q;
    REP(love, q) {
        long long pos; cin >> pos;
        printf("%c\n", answer(pos));
    }
}

int main(void) {
    ios::sync_with_stdio(false);

    init();
    reduceLevel();
    prepareTransLength();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
