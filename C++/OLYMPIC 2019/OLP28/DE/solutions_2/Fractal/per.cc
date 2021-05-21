/* Solution to "Fractal" from NWERC 2009
 *
 * Author: Per Austrin
 *
 * Algorithm: linear transformation + recurse
 */
#include <cassert>
#include <cstdio>
#include <cmath>

struct P {
  double x, y;
  P(double _x=0, double _y=0) : x(_x), y(_y) { }
  P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  P operator*(double d) const { return P(x * d, y * d); }
  P operator/(double d) const { return P(x / d, y / d); }
  double dot(const P &p)  const  { return x*p.x + y*p.y; }
  double cross(const P &p) const { return x*p.y - y*p.x; }
  double dist2() const { return dot(*this); }
  double dist() const { return sqrt(dist2()); }
};

P lintrans(const P p0, const P p1, const P q0, const P q1, const P r) {
  P dp = p1-p0, dq = q1-q0, num(dp.cross(dq), dp.dot(dq));
  double den = dp.dist2();
  return q0 + P((r-p0).cross(num), (r-p0).dot(num)) / den;
}

int n;
P p[200];
double l[200];

P get(P p0, P p1, int d, double f) {
  int i;
  for (i = 0; i < n; ++i) if (l[i+1] / l[n-1] >= f) break;
  double nf = (f*l[n-1]-l[i])/(l[i+1]-l[i]);
  if (d == 1) return lintrans(p[0], p[n-1], p0, p1, p[i]+(p[i+1]-p[i])*nf);
  P q0 = lintrans(p[0], p[n-1], p0, p1, p[i]);
  P q1 = lintrans(p[0], p[n-1], p0, p1, p[i+1]);
  return get(q0, q1, d-1, nf);
}

void solve() {
  scanf("%d", &n);
  assert(3 <= n && n <= 100);
  l[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
    assert(-1000 <= p[i].x && p[i].x <= 1000);
    assert(-1000 <= p[i].y && p[i].y <= 1000);
  }
  for (int i = 1; i < n; ++i) l[i] = l[i-1] + (p[i]-p[i-1]).dist();
  int d;
  double f;
  scanf("%d%lf", &d, &f);
  assert(1 <= d && d <= 10);
  assert(0 <= f && f <= 1);
  P res = get(p[0], p[n-1], d, f);
  printf("(%.9lf,%.9lf)\n", (double)res.x, (double)res.y);
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) solve();
  return 0;
}
