#include <cassert>
#include <iostream>

using namespace std;

const int ofs = 512;
const int dx[6] = {-1,-1,0,1,1,0};
const int dy[6] = {1,-1,-2,-1,1,2};

int answer[1<<14];
int cnt[8];
int mat[2*ofs][2*ofs];

void init() {
  for (int i=1 ; i<=5 ; i++)
    cnt[i] = 0;
  cnt[1] = cnt[2] = 1;
  for (int i=0 ; i<2*ofs ; i++)
    for (int j=0 ; j<2*ofs ; j++)
      mat[i][j] = 0;
  mat[ofs][ofs] = answer[1] = 1;
  mat[ofs+1][ofs+1] = answer[2] = 2;
  int dir=0, x=ofs, y=ofs+2;
  for (int n=3 ; n<=10000 ; n++) {
    bool ok[8];
    for (int i=1 ; i<=5 ; i++)
      ok[i] = true;
    for (int d=0 ; d<6 ; d++)
      ok[mat[x+dx[d]][y+dy[d]]] = false;
    int ix = 1;
    while (ix<=5 && !ok[ix])
      ++ix;
    assert(ix <= 5);
    for (int i=ix+1 ; i<=5 ; i++)
      if (ok[i] && cnt[i] < cnt[ix])
        ix = i;
    mat[x][y] = answer[n] = ix;
    ++cnt[ix];
    int ndir = (dir+1) % 6;
    if (mat[x+dx[ndir]][y+dy[ndir]] == 0)
      dir = ndir;
    x += dx[dir];
    y += dy[dir];
  }
}

int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << answer[n] << endl;
  }
  return 0;
}

