#include<bits/stdc++.h>
using namespace std;

#define i64 long long

i64 n,k;

i64 f(i64 x) {
	i64 res = 0;
	for(int i = 1;i <= n && i * i <= x;++i) {
		res += min(n,(i64)sqrt(x - i * i));
	}
	return res;
}

int main() {
	cin >> n >> k;
	i64 ll = 0, rr = n * n * 2, mm = n * n;
	while(ll != mm and rr != mm) {
		if(f(mm) >= k) rr = mm;
		else ll = mm;
		mm = (ll + rr)>>1;
	}
	i64 ans = mm;
	for(i64 i = ll;i <= rr;++i) if(f(i) >= k) {
		ans = i;
		break;
	}
	cout << ans << endl;
}
