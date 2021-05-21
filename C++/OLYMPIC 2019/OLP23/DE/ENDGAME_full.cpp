#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
int coord[3][N], opt_coord[3];

int main() {
  //  double stime = clock();
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i <= n; ++i) 
        for (int j = 0; j < 3; ++j) {
            cin >> coord[j][i];
        }
    
    long long sumDist = 0;
    // Sum of distance from base to dragon balls
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) sumDist += abs(coord[j][i] - coord[j][0]);
    }
    // Find the median of each axes
    for (int i = 0; i < 3; ++i) {
        sort(coord[i] + 1, coord[i] + n + 1);
        opt_coord[i] = coord[i][(n + 1) / 2];
        for (int j = 1; j <= n; ++j) {
            sumDist += abs(coord[i][j] - opt_coord[i]);
        }
    }
    cout << sumDist << endl;
    for (int i = 0; i < 3; ++i) cout << opt_coord[i] << " ";
   // double etime = clock();
 //   cerr << "Executed time: " << (etime - stime) / CLOCKS_PER_SEC * 1000 << "ms.\n";
}
