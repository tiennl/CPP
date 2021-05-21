#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int n, m, r, a[3000000];
priority_queue <pii, vector <pii>, greater <pii> > Add;
priority_queue <pii> Del;

int main()
{
    ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
    cin >> n >> r >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Add.push({a[i], i});
        Del.push({a[i], -i});
    }
    a[0] = a[n + 1] = -1e9;
    for (int i = 1; i <= m; i++) {
        while (Add.size() && (Add.top().first != a[Add.top().second] || Add.top().first <= 0)) Add.pop();
        if (!Add.size()) {
            cout << 0; return 0;
        }
        int pos = Add.top().second;
        for (int j = pos - r; j <= pos + r; j++) if (j > 0 && j <= n) {
            a[j]++;
            Add.push({a[j], j});
            Del.push({a[j], -j});
        }
        while (Del.size() && (Del.top().first != a[-Del.top().second] || Del.top().first <= 0)) Del.pop();
        if (!Del.size()) {
            cout << 0; return 0;
        }
        pos = -Del.top().second;
        for (int j = pos - r; j <= pos + r; j++) if (j > 0 && j <= n)
            a[j] =-1e9;
    }
    cout << max(0, *max_element(a + 1, a + 1 + n));
}
