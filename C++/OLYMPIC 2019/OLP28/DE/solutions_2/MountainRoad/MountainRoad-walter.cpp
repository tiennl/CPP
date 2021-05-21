#include <iostream>

using namespace std;

const int maxn = 1<<9;
const int delay = 10;
const int OO = 1<<28;

int arr[2][maxn], dur[2][maxn], dp[2][maxn][maxn];

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    int na = 0, nb = 0;
    while (n--) {
      char ab;
      int t, d;
      cin >> ws >> ab >> t >> d;
      if (ab == 'A') {
        ++na;
        arr[0][na] = t;
        dur[0][na] = d;
      } else {
        ++nb;
        arr[1][nb] = t;
        dur[1][nb] = d;
      }
    }
    for (int i=0 ; i<=na ; i++)
      for (int j=0 ; j<=nb ; j++)
        dp[0][i][j] = dp[1][i][j] = OO;
    dp[0][0][0] = dp[1][0][0] = 0;
    for (int i=0 ; i<=na ; i++)
      for (int j=0 ; j<=nb ; j++) {
        int start = max(dp[0][i][j], arr[1][j+1]);
        int end = start + dur[1][j+1];
        dp[1][i][j+1] = min(dp[1][i][j+1], end);
        for (int k=j+2 ; k<=nb ; k++) {
          start = max(start + delay, arr[1][k]);
          end = max(end + delay, start + dur[1][k]);
          dp[1][i][k] = min(dp[1][i][k], end);
        }
        start = max(dp[1][i][j], arr[0][i+1]);
        end = start + dur[0][i+1];
        dp[0][i+1][j] = min(dp[0][i+1][j], end);
        for (int k=i+2 ; k<=na ; k++) {
          start = max(start + delay, arr[0][k]);
          end = max(end + delay, start + dur[0][k]);
          dp[0][k][j] = min(dp[0][k][j], end);
        }
      }
    cout << min(dp[0][na][nb], dp[1][na][nb]) << endl;
  }
  return 0;
}

