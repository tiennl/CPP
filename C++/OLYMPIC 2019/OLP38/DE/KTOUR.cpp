#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 4100;
 
int n;
long double f[maxn][15];
int start[maxn];
long double a[maxn];
 
long double calc() {
    int m = ceil(log2(n));
    int temp = 1<<(m-1);
    int last = temp + temp - n;
    vector <int> v;
    for(int i = n - last + 1; i <= n; i++) {
        v.push_back(a[i]);
    }
    reverse(v.begin(), v.end());
    int cur = n - last;
    for(int i = n - last + 1; i <= n; i++) {
        a[++cur] = 0;
        a[++cur] = v.back();
        v.pop_back();
    }
    n = cur;
    for(int i = 1; i <= n; i++)
        f[i][0] = 1;
    for (int match = 1; match <= m; match++) {
        int sz = 1<<match;
        int cur = 0, left = 1;
        for(int i = 1; i <= n; i++) {
            cur++;
            if (cur > sz) {
                cur = 1;
                left += sz;
            }
 
            int right = left + sz - 1;
            int l = left, r = right, mid = (left + right)/2;
            if (i <= mid) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
            long double g = 0;
            for(int j = l; j <= r; j++) {
                g += f[j][match-1];
            }
            if (a[i] != 0) {
                for (int j = l; j <= r; j++) {
                    assert(i != j);
                    f[i][match] += f[j][match-1] * (a[i] / (a[j] + a[i]));
                }
             }
            f[i][match] *= f[i][match-1];
        }
 
    }
    return f[n][m];
}
 
int main() {
    if (fopen("a.txt", "r")) {
        freopen("a.txt", "r", stdin);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    swap(a[n], a[1]);
    sort(a + 1, a + n);
    reverse(a + 1, a + n);
    cout << setprecision(10) << fixed << calc();
}
