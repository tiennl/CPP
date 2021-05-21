#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-6
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)
#define maxn 2000005

int n, k, a[maxn], f[maxn], nex[maxn];

void solve(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
//  freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
  cin >> n >> k;
  For(i, 1, n) {
    cin >> a[i];
    a[i + n] = a[i];
    a[i + n + n] = a[i];
  }

  int res = 0;
  if(k == 1){
    For(i, 1, n) res |= a[i];
    cout << res << endl;
    return;
  }

  For(i, 1, 3 * n + 2) f[i] = i;

  for(int id = 30; id >= 0; id--){
    nex[3 * n + 1] = 3 * n + 1;
    nex[3 * n + 2] = 3 * n + 1;
    for(int i = 3 * n; i >= 0; i--){
      nex[i] = nex[i + 1];
      if(getbit(a[i], id)) nex[i] = i;
    }
    int smallest = inf, place = 0;
    For(i, 1, n + n) {
      nex[i] = max(nex[i], f[i]);
      if(i <= n && nex[i] - i < smallest){
        smallest = nex[i] - i;
        place = i;
      }
    }
    if(nex[place] >= place + n) continue;
    For(i, place, nex[place]){
      int u = i;
      int num = -1;
      while(u <= i + n){
        u = nex[u] + 1;
        num++;
      }
      if(num >= k){
        res = onbit(res, id);
        For(i, 1, 3 * n + 1) f[i] = nex[i];
        break;
      } 
    }
  }
  cout << res << endl;
  
}

int main(){
    solve();
  return 0;
}