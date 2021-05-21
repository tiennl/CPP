#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

int n, x[MAX], y[MAX];
int p[MAX];
int mini, maxi;

bool lol(int k, int l) {
    return y[k] < y[l] || (y[k] == y[l] && x[k] < x[l]);
}

int ccw(int k, int l, int m) {
    return x[k] * (y[l] - y[m]) + x[l] * (y[m] - y[k]) + x[m] * (y[k] - y[l]);
}

bool ang(int k, int l) {
    int s = ccw(mini, k, l);

    return s > 0 || (s == 0 && (x[k] - x[mini]) * (x[k] - x[mini]) + (y[k] - y[mini]) * (y[k] - y[mini])
                             < (x[l] - x[mini]) * (x[l] - x[mini]) + (y[l] - y[mini]) * (y[l] - y[mini]));
}

void go() {
    vector<int> v;

    mini = maxi = 0;
    for (int i = 0; i < n; ++i) {
        mini = min(mini, i, lol);
        maxi = max(maxi, i, lol);
        p[i] = i;
    }

    sort(p, p + n, ang);

    int l = 2, m = 2;
    
    while (l < n && p[m - 1] != maxi) {
        while (m > 1 && ccw(p[m - 2], p[m - 1], p[l]) < 0) v.push_back(p[--m]);
        p[m++] = p[l++];
    }

    v.insert(v.end(), p + l, p + n);
    sort(v.begin(), v.end(), lol);
    copy(v.rbegin(), v.rend(), p + m);
}

int main() {
    int t;

    for (cin >> t; t > 0; --t) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        go();
        for (int i = 0; i < n; ++i) cout << p[i] << (i + 1 < n ? ' ' : '\n');
    }

    return 0;
}
