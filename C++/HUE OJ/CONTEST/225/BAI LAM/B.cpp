#include <bits/stdc++.h>
using namespace std; 

struct COIN {
	int v;
	int i, j;
};

COIN Coin(int v, int i, int j) {
	COIN coin; coin.v = v;
	coin.i = i; coin.j = j;
	return coin;
}

bool coinSort(COIN a, COIN b) {
	return a.v < b.v;
}

bool reachable(COIN a, COIN b, int k) {
	bool bi = (a.i == b.i && abs(a.j-b.j) <= k);
	bool bj = (a.j == b.j && abs(a.i-b.i) <= k);
	bool bv = a.v != b.v;
	return (bi || bj) && bv;
}

bool origin(COIN c) {
	return (c.i == 0 && c.j == 0);
}

int main(void) {
	//freopen("B.in", "r", stdin);
	int n, k; cin >> n >> k;
	vector< vector<int> > a(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	
	vector<COIN> coins;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) coins.push_back(Coin(a[i][j], i, j));
	}
	sort(coins.begin(), coins.end(), coinSort);
	int l = coins.size();
	
	vector< vector<int> > adj(l, vector<int>(0));
	for (int i = 0; i < l; i++) {
		for (int j = i+1; j < l; j++) {
			if (reachable(coins[i], coins[j], k)) {
				adj[i].push_back(j);
			}
		}
	}
	
//	for (int i = 0; i < l; i++) {
//		for (int j = 0; j < adj[i].size(); j++) {
//			cout << adj[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	int p = 0; while (!origin(coins[p])) p++;
	vector<int> sum(l, -1); sum[p] = coins[p].v;
	vector<int> node(1, p);
	while (node.size() > 0) {
		vector<int> newNodes;
		while (node.size() > 0) {
			int i = node[node.size()-1]; node.pop_back();
			for (int j = 0; j < adj[i].size(); j++) {
				if (sum[i] + coins[adj[i][j]].v > sum[adj[i][j]]) {
					sum[adj[i][j]] = sum[i] + coins[adj[i][j]].v;
					newNodes.push_back(adj[i][j]);
				};
			}
		}
		
		for (int i = 0; i < newNodes.size(); i++) {
			node.push_back(newNodes[i]);
		}
	}

	//for (int i = 0; i < sum.size(); i++) cout << sum[i] << " ";
	//cout << endl;
	cout << *(max_element(sum.begin(), sum.end()));
	
	//fclose(stdin);
	return 0;
}
