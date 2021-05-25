#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[201];
int n = 0;

int main() {
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i].second >> a[i].first; /* S?p x?p l?i theo th?i gian k?t thúc */
	sort(a + 1,a + 1 + n);
	/* First là thòi gian k?t thúc */
	int h = 0,d = 0, ans = 0;
	for(int i = 1;i <= n;++i) {
		if(h < d) swap(h,d);
		if(h <= a[i].second) {
			h = a[i].first;
			++ans;
			continue;
		} else if(d <= a[i].second) {
			d = a[i].first;
			++ans;
		}
	}
	cout << ans << endl;
}
