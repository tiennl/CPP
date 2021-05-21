#include <iostream>

using namespace std;

unsigned cnt[1<<20];

int main() {
  int c;
  cin >> c;
  while (c--) {
    int d, n;
    cin >> d >> n;
    for (int i=0 ; i<d ; i++)
      cnt[i] = 0;
    int psum = 0;
    ++cnt[psum];
    for (int i=0 ; i<n ; i++) {
      int num;
      cin >> num;
      psum = (psum + num) % d;
      ++cnt[psum];
    }
    int res = 0;
    for (int i=0 ; i<d ; i++)
      res += cnt[i]*(cnt[i]-1)/2;
    cout << res << endl;
  }
  return 0;
}

