/*
  [NWERC'09] Divisable Subsequences
  by: Jan Kuipers
*/

#include <iostream>
#include <vector>

using namespace std;

int main () {

  int runs;
  cin>>runs;
  
  while (runs--) {

    int N,D,X=0,res=0;;
    cin>>D>>N;

    vector<int> cnt(D,0);
    cnt[0]=1;
    
    for (int i=0; i<N; i++) {
      int x;
      cin>>x;
      res += cnt[X=(X+x)%D]++;
    }

    cout<<res<<endl;
  }
  
  return 0;
}
