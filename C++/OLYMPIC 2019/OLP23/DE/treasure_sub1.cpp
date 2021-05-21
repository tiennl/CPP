#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> c(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &c[i]);

    vector<pii> e(k);
    for(int i = 0; i < k; ++i) {
        scanf("%d%d", &e[i].first, &e[i].second);
        --e[i].first; --e[i].second;
    }

    vector<int> id(k);
    for(int i = 0; i < k; ++i)
        id[i] = i;

    for(int i = 0; i < k; ++i) {
        int p;
        scanf("%d", &p); --p;

        id.erase(find(id.begin(), id.end(), p));

        long long ans = 0;

        for(int mask = 0; mask < (1 << id.size()); ++mask) {
            long long sum = 0;
            vector<bool> unlocked(n, false);

            for(int j = 0; j < id.size(); ++j) {
                int chest = ((mask>>j)&1) ? e[id[j]].second : e[id[j]].first;
                if (!unlocked[chest]) {
                    unlocked[chest] = true;
                    sum += c[chest];
                }
            }

            ans = max(ans, sum);
        }

        printf("%lld\n", ans);
    }

    return 0;
}
