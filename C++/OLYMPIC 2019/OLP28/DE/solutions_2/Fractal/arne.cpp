#include <algorithm>
#include <complex>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX = 100;

typedef complex<double> pt;

int n, x[MAX], y[MAX], d;
double f, l[MAX];
pt z[MAX];

pt warp(pt p, pt a, pt b) {
    return (p - z[0]) / (z[n - 1] - z[0]) * (b - a) + a;
}

pt doit() {
    pt a = z[0], b = z[n - 1];
    double t = f;

    l[0] = 0.0;
    for (int i = 1; i < n; ++i) l[i] = l[i - 1] + abs(z[i] - z[i - 1]);

    for (int i = 0; i < d; ++i) {
        int k = lower_bound(l + 1, l + n - 1, t * l[n - 1]) - l;
        pt a2 = warp(z[k - 1], a, b), b2 = warp(z[k], a, b);

        a = a2;
        b = b2;
        t = (t * l[n - 1] - l[k - 1]) / (l[k] - l[k - 1]);
        if (t < 0.0) t = 0.0;
        if (t > 1.0) t = 1.0;
    }

    return a + t * (b - a);
}

int main() {
    int tc;

    cout.precision(9);
    for (cin >> tc; tc > 0; --tc) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            z[i] = pt(x[i], y[i]);
        }
        cin >> d >> f;

        pt r = doit();

        cout << '(' << r.real() << ',' << r.imag() << ')' << endl;
    }

    return 0;
}
