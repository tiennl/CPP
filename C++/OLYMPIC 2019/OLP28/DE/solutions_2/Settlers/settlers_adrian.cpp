// Author: Adrian Kuegel
// Algorithm: Simulation
// Complexity: O(n)

#include <stdio.h>
#include <assert.h>

#define MAXN 10000
#define BOARDSIZE 250

char board[BOARDSIZE][BOARDSIZE];
int tiles[2 * MAXN];

int main() {
	int sx = BOARDSIZE / 2, sy = BOARDSIZE / 2;
	int cnt[6] = {0};
	int dirs[6][2] = {{1, 1}, {0, 2}, {-1, 1}, {-1, -1}, {0, -2}, {1, -1}};
	int dist = 1, n = 1;
	board[sx][sy] = cnt[1] = tiles[1] = 1;
	while(n < MAXN) {
		for (int i=0; i<6; ++i) {
			for (int j=(i == 1? 1 : 0); j<dist; ++j) {
				sx += dirs[i][0];
				sy += dirs[i][1];
				assert(!board[sx][sy]);
				bool have[6] = {false};
				for (int k=0; k<6; ++k) {
					int tx = sx + dirs[k][0];
					int ty = sy + dirs[k][1];
					assert(tx >= 0 && tx < BOARDSIZE && ty >= 0 && ty < BOARDSIZE);
					have[(int)board[tx][ty]] = true;
				}
				int place = 1;
				for (int k=2; k<6; ++k)
					if (have[place] || (!have[k] && cnt[k] < cnt[place]))
						place = k;
				board[sx][sy] = place;
				++cnt[place];
				tiles[++n] = place;
			}
		}
		++dist;
	}
	int tc;
	int rcnt = scanf("%d", &tc);
	assert(rcnt == 1);
	assert(tc > 0 && tc <= 200);
	while(tc--) {
		rcnt = scanf("%d", &n);
		assert(rcnt == 1);
		assert(n >= 1 && n <= MAXN);
		printf("%d\n", tiles[n]);
	}
	return 0;
}
