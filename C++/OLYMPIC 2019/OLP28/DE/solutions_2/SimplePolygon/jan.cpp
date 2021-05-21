/*
  [NWERC'09] Simple Polygon
  by: Jan Kuipers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double eps1 = 1.23e-7;
double eps2 = 4.56e-7;

struct point {
  int idx;
  double x,y,angle;
};

bool operator < (point a, point b) {
  return a.angle < b.angle;
}

int main () {

  int runs;
  cin>>runs;

  while (runs--) {

    int N;
    cin>>N;
    vector<point> p(N);
    double cx=0,cy=0;
    
    for (int i=0; i<N; i++) {
      p[i].idx=i;
      cin>>p[i].x>>p[i].y;
      cx+=p[i].x/N;
      cy+=p[i].y/N;
    }

    for (int i=0; i<N; i++)
      p[i].angle = atan2(p[i].y-cy+eps1 , p[i].x-cx+eps2);

    sort(p.begin(),p.end());
    
    for (int i=0; i<N; i++) {
      if (i) cout<<" ";
      cout<<p[i].idx;
    }
    cout<<endl;    
  }
    
  return 0;
}
