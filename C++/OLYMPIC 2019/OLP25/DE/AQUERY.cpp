#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
    ll sum, val;
};

struct IT {
private:
    vector<Node> t;
    int n;

    void propagate(int id, int l, int r) {
        ll &x = t[id].val;
        if (x != -1) {
            int m = (l+r)/2;
            t[2*id].val = t[2*id+1].val = x;
            t[2*id].sum = (m-l+1)*x;
            t[2*id+1].sum = (r-m)*x;
            x = -1;
        }
    }

    void update(int id, int l, int r, int i, int j, ll x) {
        if (l > j || r < i) return;
        if (i <= l && r <= j) {
            t[id].val = x;
            t[id].sum = (r-l+1)*x;
            return;
        }
        propagate(id, l, r);
        int m = (l+r)/2;
        update(2*id, l, m, i, j, x); update(2*id+1, m+1, r, i, j, x);
        t[id].sum = t[2*id].sum + t[2*id+1].sum;
    }

    long long query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id].sum;
        propagate(id, l, r);
        int m = (l+r)/2;
        return query(2*id, l, m, i, j) + query(2*id+1, m+1, r, i, j);
    }

public:
    IT(int n): n(n) {t.assign(4*n+1, {0, -1});}

    void update(int i, int j, ll x) {update(1, 1, n, i, j, x);}

    long long query(int i, int j) {return query(1, 1, n, i, j);}
};

int main () {
//    freopen("AQUERY.INP", "r", stdin);
//    freopen("AQUERY.OUT", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);

    IT t(n);

    for(int i = 0; i < q; ++i) {
        int r; ll p;
        scanf("%d%lld", &r, &p);

        int lo = 1, hi = r-1, l = r;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            ll aMid = t.query(mid, mid);
            ll x = (r-mid+1)*aMid - t.query(mid, r);

            if (x <= p) {
                l = mid;
                hi = mid-1;
            } else
                lo = mid+1;
        }

        ll aL = t.query(l, l);
        p -= (r-l+1) * aL - t.query(l, r);

        ll aNew = aL + p/(r-l+1);
        int m = l + p%(r-l+1) - 1;
        t.update(l, m, aNew + 1);
        t.update(m + 1, r, aNew);
    }

    for(int i = 1; i <= n; ++i)
        printf("%lld ", t.query(i, i));

    return 0;
}
