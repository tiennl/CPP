#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

const int maxp = 10000000;

bool prime[maxp];

int main() {
  for (int i=0 ; i<maxp ; i++)
    prime[i] = i % 2 == 1;
  prime[1] = false;
  prime[2] = true;
  for (int p=3 ; p*p<maxp ; p+=2)
    if (prime[p])
      for (int i=p*p ; i<maxp ; i+=p+p)
        prime[i] = false;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.size();
    char *p = strdup(s.c_str()), *pe = p + len;
    sort(p, pe);
    set<int> nums;
    do {
      for (char *q = p ; q<pe ; q++) {
        int num;
        assert(sscanf(q, "%d", &num) == 1);
        if (prime[num])
          nums.insert(num);
      }
    } while (next_permutation(p, pe));
    cout << nums.size() << endl;
  }
  return 0;
}

