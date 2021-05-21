/*
  [NWERC'09] Mountain Road
  by: Jan Kuipers
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

int main () {

  int runs;
  cin>>runs;

  while (runs--) {

    int N;
    cin>>N;
    VVI t(2),dt(2);
    VI T(2,0);
    
    for (int i=0; i<N; i++) {
      char c; int _t,_dt;
      cin>>c>>_t>>_dt;
      t[c-'A'].push_back(_t);
      dt[c-'A'].push_back(_dt);
      T[c-'A']++;
    }

    VVVI best(T[0]+1, VVI(T[1]+1, VI(2, INT_MAX/2)));
    best[0][0][0]=best[0][0][1]=0;

    VI n(2);
    for (n[0]=0; n[0]<=T[0]; n[0]++)
      for (n[1]=0; n[1]<=T[1]; n[1]++)
	for (int x=0; x<2; x++)
	  
	  if (n[x]<t[x].size()) {

	    int t1=best[n[0]][n[1]][1-x],t2=0;
	    int old=n[x];
	    
	    while (n[x]<T[x]) {
	      t1 = max(t1,t[x][n[x]]);
	      t2 = max(t2,t1 + dt[x][n[x]]);
	      n[x]++;
	      best[n[0]][n[1]][x] = min(best[n[0]][n[1]][x],t2);
	      t1 += 10;
	      t2 += 10;
	    }

	    n[x]=old;
	  }

    cout<<min(best[T[0]][T[1]][0],best[T[0]][T[1]][1])<<endl;
  }
  
  return 0;
}
