#include <stdio.h>

#define MAX_COLORS 5
#define MAX_TILES 10000

int totalTiles[MAX_COLORS + 1];
int tile[MAX_TILES];
bool possible[MAX_COLORS + 1];

int
main(int argc, char** argv)
{
	int numCases;
	scanf("%d", &numCases);

	tile[0] = 0;
	int circle = 1;
	int contactWith = 0;
	int curTile = 1;
	int curInCircle = 1;
	totalTiles[0] = 1;
	totalTiles[MAX_COLORS] = MAX_TILES;

	while (curTile < MAX_TILES) {
		for (int i = 0; i < MAX_COLORS; i++) {
			possible[i] = true;
		}
		if (curInCircle == circle * 6 + 1) {
			// new circle
			curInCircle = 1;
			circle++;
		} else {
			possible[tile[contactWith]] = false;
		}
		if (curInCircle == circle * 6) {
			// last in circle is in contact with first in circle
			possible[tile[curTile - circle * 6 + 1]] = false;
		}
		possible[tile[curTile - 1]] = false;
		if (curInCircle % circle != 0) {
			contactWith++;
			possible[tile[contactWith]] = false;
		}
		int selected = MAX_COLORS;
		for (int i = 0; i < MAX_COLORS; i++) {
			if (possible[i] && (totalTiles[i] < totalTiles[selected])) {
				selected = i;
			}
		}

		tile[curTile] = selected;
		totalTiles[selected]++;

		curTile++;
		curInCircle++;
	}


	int which;
	for (int i = 0; i < numCases; i++) {
		scanf("%d", &which);
		printf("%d\n", tile[which - 1] + 1);
	}

	return 0;
}
