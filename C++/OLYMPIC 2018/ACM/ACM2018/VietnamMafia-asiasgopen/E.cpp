#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1000 + 5;
int n, k, cnt;
string s;
int id[maxn];
int st[maxn];
int ed[maxn];
int dp[maxn][maxn][2][2];

int calc(int u, int k, int fa, int fb) {
    if (u == n || !k) return (fa || fb) ? -INF : 0;
    int& res = dp[u][k][fa][fb];
    if (~res) return res;
    res = -INF;
    int iu = id[u];
    if (!fa) {
        if (iu + 2 < cnt && st[iu + 1] == ed[iu + 1] && s[st[iu]] == s[st[iu + 2]]) {
            chkmax(res, calc(ed[iu + 2] + 1, k - 1, 0, 0) + ed[iu + 2] - u + 1);
            if (ed[iu + 1] - u + 1 >= 3) {
                if (iu + 3 == cnt || s[st[iu + 1]] != s[st[iu + 3]]) {
                    chkmax(res, calc(ed[iu + 1] + 1, k - 1, 1, 0) + ed[iu + 1] - u + 1);
                }
                chkmax(res, calc(ed[iu + 1] + 1, k - 1, 0, 1) + ed[iu + 1] - u + 1);
                if (st[iu + 2] < ed[iu + 2]) {
                    chkmax(res, calc(ed[iu + 1] + 1, k - 1, 0, 0) + ed[iu + 1] - u + 1);
                }
            }
            if (st[iu + 2] < ed[iu + 2]) {
                chkmax(res, calc(st[iu + 2] + 1, k - 1, 1, 0) + st[iu + 2] - u + 1);
            }
        }
        else if (iu + 1 < cnt && st[iu + 1] - u + 1 >= 3) {
            chkmax(res, calc(st[iu + 1] + 1, k - 1, 0, 0) + st[iu + 1] - u + 1);
        }
    }
    if (!fb) {
        if (u == ed[iu] && iu + 1 < cnt && st[iu + 1] < ed[iu + 1]) {
            chkmax(res, calc(ed[iu + 1] + 1, k - 1, 0, 0) + ed[iu + 1] - u + 1);
        }
    }
    if (!fa && !fb) {
        chkmax(res, calc(u + 1, k, 0, 0));
    }
    return res;
}

void chemthan() {
    int test; cin >> test;
    while (test--) {
        cin >> s >> k;
        n = sz(s);
        int ptr = 0;
        cnt = 0;
        FOR(i, 0, n + 1) {
            if (i == n || (i && s[i] != s[i - 1])) {
                assert(i - ptr == 1 || i - ptr == 2);
                FOR(j, ptr, i) {
                    id[j] = cnt;
                }
                st[cnt] = ptr;
                ed[cnt] = i - 1;
                ptr = i;
                cnt++;
            }
        }
        ms(dp, -1);
        cout << calc(0, k, 0, 0) << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
