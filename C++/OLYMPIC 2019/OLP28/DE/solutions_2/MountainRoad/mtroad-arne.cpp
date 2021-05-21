#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 123456789, GAP = 10, MAX = 200;

int num[2], arrive[2][MAX], traverse[2][MAX];

int go() {
    static int dp[MAX + 1][MAX + 1][2];

    for (int i = 0; i <= num[0]; ++i) for (int j = 0; j <= num[1]; ++j) dp[i][j][0] = dp[i][j][1] = INF;
    dp[0][0][0] = dp[0][0][1] = -INF;

    for (int i = 0; i < num[0] + num[1]; ++i) {
        for (int a = max(0, i - num[1]); a <= i && a <= num[0]; ++a) {
            int b = i - a;

            for (int enter = dp[a][b][1], leave = -INF, j = a; j < num[0]; ++j) {
                enter = max(enter, arrive[0][j]);
                leave = max(leave, enter + traverse[0][j]);
                dp[j + 1][b][0] = min(dp[j + 1][b][0], leave);
                enter += GAP;
                leave += GAP;
            }

            for (int enter = dp[a][b][0], leave = -INF, j = b; j < num[1]; ++j) {
                enter = max(enter, arrive[1][j]);
                leave = max(leave, enter + traverse[1][j]);
                dp[a][j + 1][1] = min(dp[a][j + 1][1], leave);
                enter += GAP;
                leave += GAP;
            }
        }
    }

    return min(dp[num[0]][num[1]][0], dp[num[0]][num[1]][1]);
}

int main() {
    int m, n;
    char dir;

    for (scanf("%d", &m); m > 0; --m) {
        num[0] = num[1] = 0;
        for (scanf("%d", &n); n > 0; --n) {
            scanf(" %c", &dir);
            scanf("%d%d", arrive[dir - 'A'] + num[dir - 'A'], traverse[dir - 'A'] + num[dir - 'A']);
            ++num[dir - 'A'];
        }
        printf("%d\n", go());
    }

    return 0;
}
