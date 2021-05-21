/*
  [NWERC'09] Room assignments
  by: Jan Kuipers
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,V,E;
vector<vector<int> > c;
vector<int> u;

void go (int n, int mark) {

  if (u[n]) return;
  u[n]=mark;
  
  V++;

  for (int i=0; i<c[n].size(); i++) {
    go(c[n][i],mark);
    E++;
  }    
}

int main () {

  int runs;
  cin>>runs;

  while (runs--) {

    cin>>N;
    c=vector<vector<int> >(N);
    
    for (int i=0; i<N-1; i++) {
      int a,b;
      cin>>a>>b;
      a--; b--;
      c[a].push_back(b);
      c[b].push_back(a);
    }

    vector<int> v(N);
    for (int i=0; i<N; i++)
      cin>>v[i];
	 
    u=vector<int>(N,0);
    int ncc=0, ntree=0, tree=-1;

    for (int i=0; i<N; i++)
      if (!u[i]) {
	E=V=0;
	go(i,++ncc);
	if (E/2==V-1) ntree++, tree=ncc;
      }

    if (ntree>1) {
      cout<<"impossible"<<endl;
      continue;
    }

    vector<pair<int,int> > vv;
    for (int i=0; i<N; i++)
      if (u[i]==tree) vv.push_back(make_pair(-v[i],i));
    sort(vv.begin(),vv.end());

    int a = vv[0].second;
    int b = vv.size()>1 ? vv[1].second : -1;
    
    bool samev = vv.size()>1 && vv[0].first==vv[1].first;
      
    for (int i=0; i<N; i++)
      if (u[i]!=tree && (!samev || i<b)) {
	b=i;
	break;
      }

    if (a>b) swap(a,b);
    cout<<a+1<<" "<<b+1<<endl;
  }

  return 0;
}
