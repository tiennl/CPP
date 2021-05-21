#include <cmath>
#include <iostream>

#define sqr(x) ((x)*(x))

using namespace std;

const int OO = 1<<28;
const int maxn = 256;

int spos[maxn][3], epos[maxn][3], create[maxn], shift[maxn], dist[maxn][maxn], d[maxn], pred[maxn], n2;

bool relax() {
  bool change = false;
  for (int i=0 ; i<n2 ; i++)
    for (int j=0 ; j<n2 ; j++) {
      int diw = max(d[i] + dist[i][j], create[j]) + shift[j];
      if (d[j] > diw) {
        d[j] = diw;
        pred[j] = i;
        change = true;
      }
    }
  return change;
}

void negcycle() {
  for (int i=0 ; i<n2 ; i++) {
    int k=i;
    for (int j=0 ; j<n2 && k!=-1 ; j++, k=pred[k]) ;
    if (k == -1) continue;
    int mind = d[pred[k]] + dist[pred[k]][k] - create[k];
    for (int j=pred[k] ; j!=k ; j=pred[j])
      mind = min(mind, d[pred[j]] + dist[pred[j]][j] - create[j]);
    if (mind <= 0) continue;
    d[k] -= mind;
    for (int j=pred[k] ; j!=k ; j=pred[j])
      d[j] -= mind;
  }
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    int x0, y0, z0, x1, y1, z1, n;
    cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> n;
    n2 = n+2;
    spos[n][0] = epos[n][0] = x0;
    spos[n][1] = epos[n][1] = y0;
    spos[n][2] = epos[n][2] = z0;
    spos[n+1][0] = epos[n+1][0] = x1;
    spos[n+1][1] = epos[n+1][1] = y1;
    spos[n+1][2] = epos[n+1][2] = z1;
    create[n] = create[n+1] = -OO;
    shift[n] = shift[n+1] = 0;
    for (int i=0 ; i<n ; i++)
      cin >> spos[i][0] >> spos[i][1] >> spos[i][2] >> epos[i][0] >> epos[i][1] >> epos[i][2] >> create[i] >> shift[i];
    for (int i=0 ; i<n2 ; i++) {
      for (int j=0 ; j<n2 ; j++)
        dist[i][j] = (int) ceil(sqrt(sqr(epos[i][0]-spos[j][0])+sqr(epos[i][1]-spos[j][1])+sqr(epos[i][2]-spos[j][2])));
      d[i] = OO;
      pred[i] = -1;
    }
    d[n] = 0;
    while (relax())
      negcycle();
    cout << d[n+1] << endl;
  }
  return 0;
}

