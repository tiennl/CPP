#define SPEED cin.sync_with_stdio(0); cout.sync_with_stdio(0); cin.tie(0); cout.tie();
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;

vector<vector<char> > a;
vector<vector<char> > b = {{32, 47, 92, 32}, {47, 95, 95, 92}};

void in(int x, int y) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++) a[i+x][j+y] = b[i][j];
}

void duyet(int l, int x, int y) {
	if (l == 4) {
		in(x, y);
		return;
	}
	duyet(l/2, x		, y + l/4);
	duyet(l/2, x+ l/4	, y);
	duyet(l/2, x+ l/4	, y + l/2);
}

int main(){
    {/*---- Dung Quen Lap Nao Truoc Khi Code >< ---*/
    	#ifdef ONLINE_JUDGE
			SPEED
		#endif
		#ifndef ONLINE_JUDGE
			freopen("in.cpp", "r", stdin);
			freopen("out.cpp", "w", stdout);
		#endif
	}
	{/*-----Code-----*/}
	int t;
	while (cin >> t) {
		t--;
		if (t == -1) break;
		int l = 4*pow(2,t);
		a.clear();
		a = vector<vector<char> > (l/2, vector<char> (l, ' '));
		duyet(l, 0, 0);
		rep(i, 0, l/2) {
			rep(j, 0, l) cout << a[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}


