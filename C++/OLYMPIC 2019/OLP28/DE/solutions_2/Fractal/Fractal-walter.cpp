#include <cassert>
#include <complex>
#include <iostream>

using namespace std;

const int maxn = 1<<8;

typedef complex<double> comp;

comp poly[maxn];
double dist[maxn];
int n;

comp recurse(int d, double f, comp c) {
  for (int i=0 ; i<n-1 ; f-=dist[i++])
    if (f <= dist[i])
      return c * (poly[i] + (d==1 ? (poly[i+1]-poly[i]) * f / dist[i] : recurse(d-1, f / dist[i], (poly[i+1]-poly[i]) / poly[n-1])));
  assert(0);
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(12);
  int c;
  cin >> c;
  while (c--) {
    cin >> n;
    for (int i=0 ; i<n ; i++) {
      double x, y;
      cin >> x >> y;
      poly[i] = comp(x, y);
    }
    comp ofs = poly[0];
    for (int i=0 ; i<n ; i++)
      poly[i] -= ofs;
    double total = 0.0;
    for (int i=0 ; i<n-1 ; i++)
      total += dist[i] = abs(poly[i]-poly[i+1]);
    for (int i=0 ; i<n-1 ; i++)
      dist[i] /= total;
    int d;
    double f;
    cin >> d >> f;
    cout << ofs + recurse(d, f, 1) << endl;
  }
  return 0;
}

