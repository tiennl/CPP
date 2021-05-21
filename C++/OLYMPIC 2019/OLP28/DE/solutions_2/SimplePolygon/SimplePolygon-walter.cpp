#include <algorithm>
#include <cassert>
#include <complex>
#include <iostream>
#include <vector>

#define eps          1.0e-9
#define SGN(x)       ((x)<-eps?-1:(x)>eps?1:0)
#define DET(a,b,c,d) ((a)*(d)-(b)*(c))

using namespace std;

typedef complex<double> comp;
typedef vector<comp> vc;
typedef vector<int> vi;

int startpos(const vc p) {
  int j = 0;
  for (int k=1 ; k<(int)p.size() ; k++)
    if (imag(p[k]) < imag(p[j]) ||
        (imag(p[k]) == imag(p[j]) && real(p[k]) < real(p[j])))
      j = k;
  return j;
}

int ccw(comp a, comp b, comp c) {
  double d = DET(real(b-a), real(c-a), imag(b-a), imag(c-a));
  return SGN(d);
}

vc poly;
comp p0;

bool acmp(const int x, const int y) {
  int c = ccw(poly[x], p0, poly[y]);
  if (c < 0) return true;
  if (c > 0) return false;
  return abs(poly[x]-p0) < abs(poly[y]-p0);
}

vi chull() {
  int sw = startpos(poly);
  p0 = poly[sw];
  vi perm;
  for (int i=0 ; i<(int)poly.size() ; i++)
    perm.push_back(i);
  sort(perm.begin(), perm.end(), acmp);
  assert(perm[0] == sw);
  vi stack(perm.begin(), perm.begin()+3);
  for (int i=3 ; i<(int)perm.size() ; i++) {
    while (ccw(poly[stack[stack.size()-2]], poly[stack.back()], poly[perm[i]]) < 0)
      stack.pop_back();
    stack.push_back(perm[i]);
  }
  return stack;
}

bool cmp(const int x, const int y) {
  if (imag(poly[x]) > imag(poly[y])) return true;
  if (imag(poly[x]) < imag(poly[y])) return false;
  if (real(poly[x]) > real(poly[y])) return true;
  return false;
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    poly.clear();
    for (int i=0 ; i<n ; i++) {
      double x, y;
      cin >> x >> y;
      poly.push_back(comp(x, y));
    }
    vi ch = chull();
    int nw = 0;
    for (int i=0 ; i<(int)ch.size() ; i++)
      if (imag(poly[ch[i]]) > imag(poly[ch[nw]]) ||
          (imag(poly[ch[i]]) == imag(poly[ch[nw]]) && real(poly[ch[i]]) < real(poly[ch[nw]])))
        nw = i;
    vector<bool> done(n);
    for (int i=0 ; i<=nw ; i++) {
      done[ch[i]] = true;
      if (i>0)
        cout << ' ';
      cout << ch[i];
    }
    vi perm(n);
    for (int i=0 ; i<n ; i++)
      perm[i] = i;
    sort(perm.begin(), perm.end(), cmp);
    for (int i=0 ; i<n ; i++)
      if (!done[perm[i]])
        cout << ' ' << perm[i];
    cout << endl;
  }
  return 0;
}

