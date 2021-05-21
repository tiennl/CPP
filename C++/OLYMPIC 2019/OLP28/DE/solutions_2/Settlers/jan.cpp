/*
  [NWERC'09] Settlers of Catan
  by: Jan Kuipers
*/

#include <iostream>
#include <vector>

using namespace std;

const int BMAX = 200;
const int dx[6] = { 1, 0,-1,-1, 0, 1};
const int dy[6] = { 0, 1, 1, 0,-1,-1};

int d,x,y;
vector<int> n,cnt;
vector<vector<int> > b;

int main () {

  b=vector<vector<int> >(BMAX, vector<int>(BMAX, -1));
  cnt=vector<int>(5,0);
  
  x=y=BMAX/2;
  d=0;

  cnt[b[x][y]=0]++;
  n.push_back(0);
  x+=dx[d];
  y+=dy[d];
  d+=2;

  cnt[b[x][y]=1]++;
  n.push_back(1);
  x+=dx[d];
  y+=dy[d];
  
  for (int i=0; i<=BMAX*BMAX/2; i++) {
    vector<int> pos(5,1);
    for (int i=0; i<6; i++) {
      int a = b[x+dx[i]][y+dy[i]];
      if (a!=-1) pos[a]=0;
    }

    int best=-1;
    for (int r=0; r<5; r++)
      if (pos[r] && (best==-1 || cnt[r]<cnt[best]))
	best=r;

    b[x][y]=best;
    n.push_back(best);
    cnt[best]++;
    
    while (b[x+dx[(d+1)%6]][y+dy[(d+1)%6]]==-1) d=(d+1)%6;
    x+=dx[d];
    y+=dy[d];
  }

  int runs;
  cin>>runs;
  
  while (runs--) {
    cin>>x;
    cout<<n[x-1]+1<<endl;
  }    

  return 0;
}
