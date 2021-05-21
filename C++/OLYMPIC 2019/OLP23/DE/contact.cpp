#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0, nxt[1000000][26], c[1000000], e[1000000];

void add(const string &s)
{
    int u = 0;
    bool stop = false;
    for(int i = 0; i < s.length(); ++i)
    {
        if (!nxt[u][s[i]]) nxt[u][s[i]] = ++cnt;
        u = nxt[u][s[i]];
        c[u]++;
        if (!stop) cout << s[i];
        if (c[u] == 1) stop = true;
    }
    e[u]++;
    if (!stop) cout << " " << e[u];
    cout << "\n";
}

int main()
{
    //freopen("contact.inp", "r", stdin);
    //freopen("contact.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        add(s);
    }
}
