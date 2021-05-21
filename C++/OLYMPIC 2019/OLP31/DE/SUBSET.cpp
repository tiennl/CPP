#include <bits/stdc++.h>

using namespace std;

int n, k;
int cnt[111];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        cnt[x % k]++;
    }
    int answer = min(1, cnt[0]) + (k % 2 == 0) * min(1, cnt[k / 2]);
    for (int i = 1; i < (k + 1) / 2; ++i) {
        answer += max(cnt[i], cnt[k - i]);
        //cerr << i << " " << cnt[i] << " " << cnt[k - i] << "\n";
    }
    printf("%d\n", answer);
    return 0;
}