// Author: Adrian Kuegel
// Algorithm: depth first search
// Complexity: O(n)
// Solution idea: see solOutline.tex
// for a simpler solution idea, see room_assignments.java

#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXNODES 50000

typedef vector<int> VI;

VI adj[MAXNODES];
int v[MAXNODES];
int component_id[MAXNODES];

// returns number of (directed) edges - 2 * number of nodes
// -> a value < 0 iff component contains no cycle
int getComponent(int cur_node, int comp_id) {
	if (component_id[cur_node] > 0)
		return 0;
	component_id[cur_node] = comp_id;
	int ret = adj[cur_node].size() - 2;
	for (VI::iterator it=adj[cur_node].begin(); it!=adj[cur_node].end(); ++it)
		ret += getComponent(*it, comp_id);
	return ret;
}

int main() {
	int tc;
	// read in the number of test cases
	scanf("%d", &tc);
	assert(tc > 0 && tc <= 200);
	while(tc--) {
		int n, a, b;
		// read in the number of rooms / persons
		scanf("%d", &n);
		assert(n > 1 && n <= MAXNODES);
		// intialize data structures
		for (int i=0; i<n; ++i) {
			adj[i].clear();
			component_id[i] = 0;
		}
		// read in the room choices and build the graph
		for (int i=1; i<n; ++i) {
			scanf("%d %d", &a, &b);
			assert(a < b && a >= 1 && b <= n);
			adj[a-1].push_back(b-1);
			adj[b-1].push_back(a-1);
		}
		// read in the room ratings
		for (int i=0; i<n; ++i) {
			scanf("%d", &v[i]);
			assert(v[i] > 0 && v[i] <= 1000000);
		}
		// determine the critical component without a cycle
		// there must exist at least one such component because number of
		// edges is n-1, number of nodes is n
		int critical_component = 0, n_components = 0;
		bool impossible = false;
		for (int i=0; i<n && !impossible; ++i)
			if (component_id[i] == 0) {
				++n_components;
				if (getComponent(i, n_components) < 0) {
					// there is already a critical component -> impossible
					if (critical_component > 0)
						impossible = true;
					critical_component = n_components;
				}
			}
		// Case 1 - more than one critical component
		if (impossible) {
			puts("impossible");
			continue;
		}
		int bestA = 0, bestB = 0;
		// Case 2 - at least two components
		if (n_components > 1) {
			// first determine room with highest rating in the critical component
			for (int i=0; i<n; ++i)
				if (component_id[i] == critical_component && v[i] > bestA) {
					bestA = v[i];
					a = i;
				}
			// now select the room with smallest id which is either in another
			// component, or has the same (highest) rating as room a
			for (int i=0; i<n; ++i)
				if (component_id[i] != critical_component
				|| (v[i] == bestA && i != a)) {
					b = i;
					break;
				}
		}
		// Case 3 - only one component
		else {
			// select the two nodes with the highest rating
			for (int i=0; i<n; ++i)
				if (v[i] > bestA) {
					bestB = bestA;
					b = a;
					a = i;
					bestA = v[i];
				}
				else if (v[i] > bestB) {
					bestB = v[i];
					b = i;
				}
		}
		// take care to print the nodes in the correct order
		if (a > b)
			swap(a, b);
		printf("%d %d\n", a+1, b+1);
	}
	return 0;
}
