#include <stdio.h>
#include <vector>

#define MAX_ROOMS 50000

using namespace std;

vector<int> adjList[MAX_ROOMS];
int rating[MAX_ROOMS];

int edges[MAX_ROOMS];
int nodes[MAX_ROOMS];
int comp[MAX_ROOMS];
bool visited[MAX_ROOMS];

int numComponents;
int numEdges, numNodes;

void
dfs(int curNode)
{
	if (visited[curNode]) {
		return;
	}
	visited[curNode] = true;
	comp[curNode] = numComponents;
	numNodes++;

	for (unsigned int i = 0; i < adjList[curNode].size(); i++) {
		int nextNode = adjList[curNode][i];
		dfs(nextNode);

		numEdges++;
	}
}

int
main(int argc, char **argv)
{
	int numCases;
	scanf("%d", &numCases);

	while (numCases) {
		--numCases;

		int numRooms;
		scanf("%d", &numRooms);

		for (int i = 0; i < numRooms; i++) {
			adjList[i].clear();
		}
		int from, to;
		for (int i = 0; i < numRooms - 1; i++) {
			scanf("%d%d", &from, &to);
			from--; to--;
			adjList[from].push_back(to);
			adjList[to].push_back(from);
		}

		for (int i = 0; i < numRooms; i++) {
			scanf("%d", &rating[i]);
			visited[i] = false;
		}

		vector<int> trees;
		numComponents = 0;
		bool possible = true;
		for (int i = 0; i < numRooms; i++) {
			if (!visited[i]) {
				numEdges = 0;
				numNodes = 0;
				dfs(i);

				numEdges /= 2; // traversed each edge twice
				if (numEdges > numNodes) {
					// impossible when components with multiple double edges, or triple edges
					possible = false;
					break;
				} else if (numEdges == numNodes) {
					// throw away components with single double edge
				} else { 
					// hey, found a tree!
					trees.push_back(numComponents);
				}

				numComponents++;
			}
		}

		if (!possible) {
			// see above
			puts("impossible");
			continue;
		}
		if (trees.size() > 1) {
			// more than one tree -> triple edge, where are you?
			puts("impossible");
			continue;
		}

		int best = 0;
		int secondBest =  0;
		int bestId = numRooms;
		int secondBestId = numRooms;
		// select the two best of the tree
		for (int i = 0; i < numRooms; i++) {
			if (comp[i] != trees[0]) {
				continue;
			}
			if (best < rating[i]) {
				secondBest = best;
				secondBestId = bestId;

				best = rating[i];
				bestId = i;
			} else if (secondBest < rating[i]) {
				secondBest = rating[i];
				secondBestId = i;
			}
		}

		if (numComponents > 1) {
			// either choose the best two of the tree
			for (int i = 0; i < numRooms; i++) {
				if (comp[i] != trees[0] && (secondBest < best || (secondBest == best && i < secondBestId))) {
					// node is not part of the tree, thus it forces the "best" value
					// if secondBest already == best, choose lower id
					secondBest = rating[i];
					secondBestId = i;
					break;
				}
			}
		}

		if (bestId > secondBestId) {
			int tmp = bestId;
			bestId = secondBestId;
			secondBestId = tmp;
		}

		printf("%d %d\n", bestId + 1, secondBestId + 1);
	}

	return 0;
}
