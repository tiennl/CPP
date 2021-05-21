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

const long long MOD = 1000000007LL;

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

long long getToken(long long previousHash, string transaction, long long result) {
    long long v = previousHash;
      for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007;
      }
    long long tmp = ((result - 7 * v) % MOD + MOD) % MOD;
    return tmp;
}

const string message = "gspvh";
const int mul = (int)1e7;

void process(void) {
    int code; cin >> code;
    REP(love, 2) {
        int newCode = (1 + rand() % 100) * mul;
//        cerr << newCode << endl;
        cout << message << " " << getToken(code, message, newCode) << endl;
        code = newCode;
    }
}

int main(void) {
//    cerr << getToken(140000000, "charlie-pays-to-eve-9-sg-coins", 930000000) << endl;
//    cerr << getToken(930000000, "icpc-sg-2018-at-nus", 730000000) << endl;
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
