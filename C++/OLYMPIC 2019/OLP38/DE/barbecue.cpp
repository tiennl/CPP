#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int MAXX = 1000;
const int MOD = 1000000007;

int power(int x, int n) {
    int ans = 1;
    while (n) {
        if (n&1) ans = (1LL*ans*x) % MOD;
        x = (1LL*x*x) % MOD;
        n >>= 1;
    }
    return ans;
}

int add(int &a, int b) {
    a = (a + b) % MOD;
}

int n, a[MAXN], b[MAXN], dp[2*MAXX+1][2*MAXX+1], c[4*MAXX+1][4*MAXX+1];

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++dp[MAXX - a[i]][MAXX - b[i]];
    }

    for(int x = 0; x <= 2*MAXX; ++x) {
        for(int y = 0; y <= 2*MAXX; ++y) {
            if (x > 0)
                add(dp[x][y], dp[x-1][y]);
            if (y > 0)
                add(dp[x][y], dp[x][y-1]);
        }
    }

    c[0][0] = 1;
    for(int n = 1; n <= 4*MAXX; ++n) {
        c[n][0] = 1;
        for(int k = 1; k <= n; ++k)
            c[n][k] = (c[n-1][k-1] + c[n-1][k]) % MOD;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        add(ans, dp[MAXX + a[i]][MAXX + b[i]]);
        add(ans, MOD - c[2*(a[i] + b[i])][2*a[i]]);
    }
    ans = (1LL * ans * power(2, MOD - 2)) % MOD;

    cout << ans;

    return 0;
}


