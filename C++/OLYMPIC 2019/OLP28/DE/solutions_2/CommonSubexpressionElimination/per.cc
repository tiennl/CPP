/* Solution to "Common Subexpression Elimination" from NWERC 2009
 *
 * Author: Per Austrin
 *
 * Algorithm: greedy + hashing.  (The hashing is sort of crappy so it
 * is probably not too hard to break the solution with a carefully
 * crafted case.)
 */
#include <cstdio>
#include <cctype>
#include <cassert>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 1099511627791LL;

int enc(char *s) {
  int res = 0;
  for ( ; *s && islower(*s); ++s)
    res = 27*res + (*s-'a'+1);
  return res;
}

int primes[12] = {531457, 531481, 531497, 531521, 531547, 531551,
		  531569, 531571, 531581, 531589, 531611, 531613};

ll mix(int f, ll a, ll b, int d) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  ll L = (a * primes[d%6] + b * primes[d%6 + 6] + f);
  assert(0 <= L && L < (1LL<<62));
  return L % MOD;
}

struct tree {
  char f[8];
  int fv, d;
  ll tv;
  tree *l, *r;
  tree(char *&s): d(-1), tv(-1), l(0), r(0) {
    int len = 0;
    while (*s && islower(*s)) f[len++] = *s++, assert(len <= 4);
    f[len] = 0;
    fv = enc(f);
    if (*s == '(') {
      l = new tree(++s); assert(*s == ',');
      r = new tree(++s); assert(*s == ')');
      ++s;
    } else
      assert(*s == ')' || *s == ',' || !*s);
  }

  int depth() { 
    if (d == -1) d = 1 + (l ? max(l->depth(), r->depth()) : 0);
    return d;
  }
  ll value() {
    if (tv == -1) tv = l ? mix(fv, l->value(), r->value(), depth()) : -fv;
    return tv;
  }
  
  void print(map<ll, int> &seen) {
    int &id = seen[value()];
    if (id) printf("%d", id);
    else {
      id = seen.size();
      printf("%s", f);
      if (l) printf("("), l->print(seen), printf(","), r->print(seen), printf(")");
    }
  }
};

char input[5000000];

void solve() {
  scanf("%s", input);
  char *s = input;
  tree T(s);
  map<ll, int> id;
  T.print(id);
  printf("\n");
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) solve();
  return 0;
}
