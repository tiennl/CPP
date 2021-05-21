/*
  [NWERC'09] Wormholes
  by: Jan Kuipers
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <cmath>
#include <climits>

using namespace std;

struct point { int x,y,z; };

int dist (point a, point b) {
  return (int)ceil(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
}
	     
int main() {

  int runs;
  cin>>runs;

  while (runs--) {
    
    vector<point> pfr(2),pto;
    cin>>pfr[0].x>>pfr[0].y>>pfr[0].z;
    cin>>pfr[1].x>>pfr[1].y>>pfr[1].z;

    int N;
    cin>>N;
    N+=2;
    
    pfr.resize(N);
    pto=pfr;

    vector<int> t0(N,-INT_MAX), dt(N,0);
    
    for (int i=2; i<N; i++) {
      cin>>pfr[i].x>>pfr[i].y>>pfr[i].z;
      cin>>pto[i].x>>pto[i].y>>pto[i].z;
      cin>>t0[i]>>dt[i];
    }
    
    vector<int> best(N, INT_MAX/2);
    best[0]=0;
    
    vector<int> prev(N,-1);
    vector<int> prevm(N,-1);
    
    bool change=true;

    while (change) {

      change = false;
      int incycle = -1;
      
      for (int times=0; times<N; times++)
	for (int i=0; i<N; i++)
	  for (int j=0; j<N; j++)
	    for (int m=0; m<2; m++) {
	      int nbest;
	      if (m==0)
		nbest = best[i] + dist(pto[i],pto[j]);
	      else {
		nbest = best[i] + dist(pto[i],pfr[j]);
		nbest = max(nbest, t0[j]);
		nbest += dt[j];
	      }

	      if (nbest < best[j]) {
		best[j] = nbest;
		prev[j] = i;
		prevm[j] = m;
		change = true;
		if (times==N-1) incycle = j;
	      }
	  }

      if (incycle != -1) {

	deque<int> cycle;
	vector<bool> used(N,false);

	while (!used[incycle]) {
	  cycle.push_back(incycle);
	  used[incycle]=true;
	  incycle=prev[incycle];
	}

	while (cycle.front()!=incycle)
	  cycle.pop_front();

	int cut=INT_MAX;
	for (int ii=0; ii<(int)cycle.size(); ii++) {
	  int i=cycle[ii];
	  if (prevm[i]) cut = min(cut, best[i] - dt[i] - t0[i]);
	}

	for (int i=0; i<(int)cycle.size(); i++)
	  best[cycle[i]] -= cut;
      }
    }

    cout<<setprecision(10)<<best[1]<<endl;
  }  

  return 0;
}
