// Author: Adrian Kuegel

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <math.h>
#include <complex>
using namespace std;

typedef complex<double> point;

point p[100];
double dists[100];
double total_length;
int n;

void solve(int d, point s, double scale, double rot_phi, double f) {
	if (!d) {
		s += polar(f * scale * abs(p[n-1]), rot_phi);
		cout << "(" << s.real() << "," << s.imag() << ")" << endl;
		return;
	}
	for (int i=1; i<n; ++i) {
		double part = dists[i] / total_length;
		if (part >= f) {
			s += polar(scale * abs(p[i-1]), rot_phi + arg(p[i-1]));
			solve(d-1, s, scale * dists[i] / abs(p[n-1]), rot_phi + arg(p[i]-p[i-1]), f * total_length / dists[i]);
			return;
		}
		f -= part;
	}
	assert(0);
}

int main() {
	int c;
	scanf("%d", &c);
	assert(c >= 1 && c <= 200);
	cout.precision(9);
	while(c--) {
		int x, y, d;
		scanf("%d", &n);
		assert(n >= 3 && n <= 100);
		total_length = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d %d", &x, &y);
			assert(x >= -1000 && x <= 1000 && y >= -1000 && y <= 1000);
			p[i] = point(x, y);
			if (i) {
				dists[i] = abs(p[i] - p[i-1]);
				total_length += dists[i];
			}
		}
		for (int i=1; i<n; ++i)
			assert(dists[i] < abs(p[n-1]-p[0]));
		assert(total_length < 2 * abs(p[n-1]-p[0]));
		double f;
		scanf("%d %lf", &d, &f);
		assert(d >= 1 && d <= 10);
		assert(f >= 0 && f <= 1);
		point s = p[0];
		for (int i=0; i<n; ++i)
			p[i] -= s;
		double phi = arg(p[n-1]);
		point rot(cos(-phi), sin(-phi));
		for (int i=1; i<n; ++i)
			p[i] *= rot;
		solve(d, s, 1, phi, f);
	}
	return 0;
}
