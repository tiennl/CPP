/* Solution to "An Industrial Spy" from NWERC 2009
 *
 * Author: Per Austrin
 *
 * Algorithm: brute force
 */
#include <cstdio>
#include <cstring>

bool isprime(int x) {
  if (x < 2) return false;
  for (int r = 2; r*r <= x; ++r) if (x % r == 0) return false;
  return true;
}

int f[10];

int gen(int x) {
  int ans = isprime(x);
  for (int i = !x; i < 10; ++i) if (f[i]) --f[i], ans += gen(10*x + i), ++f[i];
  return ans;
}

void solve() {
  char digs[10];
  scanf("%s", digs);
  memset(f, 0, sizeof(f));
  for (char *p = digs; *p; ++p) ++f[*p-'0'];
  printf("%d\n", gen(0));
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) solve();
  return 0;
}
