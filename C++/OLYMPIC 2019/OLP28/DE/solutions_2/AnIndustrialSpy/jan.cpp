/*
  [NWERC'09] An industrial spy
  by: Jan Kuipers
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt;

bool isprime (int n) {

  if (n<2) return false;
    
  for (int d=2; d*d<=n; d++)
    if (n%d==0) return false;
  
  return true;
}

int go (int n) {

  int res=0;
  if (isprime(n)) res++;

  for (int d=0; d<10; d++)
    if ((n>0 || d>0) && cnt[d]) {
      cnt[d]--;
      res += go(10*n+d);
      cnt[d]++;
    }
  
  return res;
}

int main () {

  int runs;
  cin>>runs;

  while (runs--) {

    string s;
    cin>>s;

    cnt=vector<int>(10,0);
    for (int i=0; i<s.size(); i++)
      cnt[s[i]-'0']++;
    
    cout<<go(0)<<endl;    
  }  
  
  return 0;
}
