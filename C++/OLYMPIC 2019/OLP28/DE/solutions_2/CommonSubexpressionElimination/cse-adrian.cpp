// problem: Common Subexpression Elimination
// author : Adrian Kuegel
// date   : 2009.05.25
// method : recursive-descent, bottom-up merging
// runtime: O(n*log n)

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <map>

using namespace std;

#define MAXNODES 50000

typedef map<long long, int> MLLI;

int n, number_of_nodes;
MLLI nodes;
char c;
int codes[MAXNODES], pointers[MAXNODES][2];

// returns id of the node representing the current subtree
int doit() {
	c = getchar();
	assert(c >= 'a' && c <= 'z');
	int code = 26 + c - 'a';
	int cnt = 1;
	int cur_node = ++number_of_nodes;
	int curn = n++;
	assert(n <= MAXNODES);
	while(islower(c = getchar())) {
		++cnt;
		assert(cnt <= 4);
		code = code * 26 + (c - 'a');
	}
	long long left_id = 0, right_id = 0;
	if (c == '(') {
		// parse left subtree
		pointers[curn][0] = n;
		left_id = doit();
		assert(c == ',');
		// parse right subtree
		pointers[curn][1] = n;
		right_id = doit();
		assert(c == ')');
		if (nodes.count((left_id << 48) + (right_id << 32) + code)) {
			--number_of_nodes;
			codes[curn] = -nodes[(left_id<<48) + (right_id << 32) + code];
		}
		else {
			nodes[(left_id << 48) + (right_id << 32) + code] = cur_node;
			codes[curn] = code;
		}
		c = getchar();
	}
	else {
		pointers[curn][0] = pointers[curn][1] = -1;
		if (nodes.count(code)) {
			--number_of_nodes;
			codes[curn] = -nodes[code];
		}
		else {
			nodes[code] = cur_node;
			codes[curn] = code;
		}
	}
	return nodes[(left_id << 48) + (right_id << 32) + code];
}

void print(int node_id) {
	if (codes[node_id] < 0)
		printf("%d", -codes[node_id]);
	else {
		char name[4];
		int l = 0;
		while(codes[node_id] >= 26) {
			name[l++] = 'a' + codes[node_id] % 26;
			codes[node_id] /= 26;
		}
		while(l--)
			putchar(name[l]);
		if (pointers[node_id][0] >= 0) {
			putchar('(');
			print(pointers[node_id][0]);
			putchar(',');
			print(pointers[node_id][1]);
			putchar(')');
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	assert(tc >= 1 && tc <= 200);
	while((c = getchar()) != '\n');
	while(tc--) {
		number_of_nodes = n = 0;
		nodes.clear();
		doit();
		assert(c == '\n');
		print(0);
		putchar('\n');
	}
	return 0;
}

