#include <algorithm>
#include <iostream>

using namespace std;

const int LEN = 50000, MAX = 1000000;

int m, n, a[LEN], b[MAX];

int go() {
    int r = 0;

    b[0] = 1;
    fill(b + 1, b + m, 0);
    for (int s = 0, i = 0; i < n; ++i) {
        s = (s + a[i]) % m;
        r += b[s]++;
    }

    return r;
}

int main() {
    int t;

    for (cin >> t; t > 0; --t) {
        cin >> m >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << go() << endl;
    }

    return 0;
}
