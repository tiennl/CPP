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

int main(){
    {/*---- Dung Quen Lap Nao Truoc Khi Code >< ---*/
    	#ifdef ONLINE_JUDGE
			SPEED
		#endif
		#ifndef ONLINE_JUDGE
			//freopen("in.cpp", "r", stdin);
		#endif
	}
	{/*-----Code-----*/}
	int n;
	cin >> n;
	vector<vector<int > > a (n, vector<int> (n));
	for (int k = 1, i = 0, j = 0; k <= n*n; k++, i++, j++) {
		i %= n;
		j %= n;
		a[i][j] = k;
		if (j+1 == n) i--;
	}
	
	
	rep(i, 0, n) {
		rep(j, 0, n) cout << a[i][j] << " ";
		cout << (n*(n*n+1)/2) << endl;
	}
	
	return 0;
}

