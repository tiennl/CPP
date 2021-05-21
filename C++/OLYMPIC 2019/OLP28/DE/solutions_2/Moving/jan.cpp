/*
  [NWERC'09] Moving to Nuremberg
  by: Jan Kuipers
*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int N;
vector<vector<int> > c,t;
vector<int> f;
vector<long long> nsum,tsum;

void go1 (int n, int prev=-1) {

  tsum[n] = 0;
  nsum[n] = f[n];
  
  for (int i=0; i<(signed) c[n].size(); i++) {
    int j=c[n][i];
    if (j==prev) continue;

    go1(j,n);
    tsum[n] += tsum[j] + nsum[j]*t[n][i];
    nsum[n] += nsum[j];
  }
}

void go2 (int n, int prev=-1, long long time=0) {

  if (prev!=-1)
    tsum[n] = tsum[prev] + (nsum[0]-2*nsum[n]) * time;

  for (int i=0; i<(signed) c[n].size(); i++)
    if (c[n][i]!=prev) go2(c[n][i],n,t[n][i]);
}

int main () {

  int runs;
  cin>>runs;

  while (runs--) {

    cin>>N;
    
    c=t=vector<vector<int > >(N);
    for (int i=0; i<N-1; i++) {
      int A,B,T;
      cin>>A>>B>>T;
      A--;
      B--;
      c[A].push_back(B);
      t[A].push_back(T);
      c[B].push_back(A);
      t[B].push_back(T);
    }

    f=vector<int>(N,0);
    int F;
    cin>>F;
    
    for (int i=0; i<F; i++) {
      int A,T;
      cin>>A>>T;
      A--;
      f[A]=T;
    }

    nsum=tsum=vector<long long>(N);
    go1(0);
    go2(0);
    
    long long res=LONG_LONG_MAX;
    for (int i=0; i<N; i++)
      res = min(res,tsum[i]);

    cout<<2*res<<endl;
    bool first=true;
    for (int i=0; i<N; i++)
      if (tsum[i]==res) {
	if (first)
	  first=false;
	else
	  cout<<" ";
	cout<<i+1;
      }
    cout<<endl;      
  }

  return 0;
}
