#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

int n;
int coord[3][N], opt_coord[3];

long long f(int dest[] ) {
    long long sumDist = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j)  {
            // From base to dragon balls
            sumDist += abs(coord[j][i] - coord[j][0]);
            // From dragon ball to destination
            sumDist += abs(coord[j][i] - dest[j]);
        }
    }
    return sumDist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i <= n; ++i) 
        for (int j = 0; j < 3; ++j) {
            cin >> coord[j][i];
        }

    for (int j = 0; j < 3; ++j) opt_coord[j] = 0;
    for (int x = 0; x <= *max_element(coord[0] + 1, coord[0] + n + 1); ++x) {
        for (int y = 0; y <= *max_element(coord[1] + 1, coord[1] + n + 1); ++y) {
            for (int z = 0; z <= *max_element(coord[2] + 1, coord[2] + n + 1); ++z) {
                int dest[3] = {x, y, z};
                if (f(dest) < f(opt_coord)) {
                    copy(dest, dest + 3, opt_coord);
                }
            }
        }
    }
    cout << f(opt_coord) << endl;
    for (int i = 0; i < 3; ++i) cout << opt_coord[i] << ' ';
}