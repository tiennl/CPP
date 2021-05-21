// Author: Adrian Kuegel
// Algorithm: Simulation
// Complexity: O(n)

import java.util.*;

public class settlers {
	final static int MAXN = 10000;
	final static int BOARDSIZE = 250;
	public static void main(String [] args) throws Exception {
		int [][] board = new int[BOARDSIZE][BOARDSIZE];
		int [] tiles = new int[2 * MAXN];
		int sx = BOARDSIZE / 2, sy = BOARDSIZE / 2;
		int [] cnt = new int[6];
		int [] dx = new int[6];
		int [] dy = new int[6];
		dx[0] = 1; dy[0] = 1;
		dx[1] = 0; dy[1] = 2;
		dx[2] = -1; dy[2] = 1;
		dx[3] = -1; dy[3] = -1;
		dx[4] = 0; dy[4] = -2;
		dx[5] = 1; dy[5] = -1;
		int dist = 1, n = 1;
		board[sx][sy] = cnt[1] = tiles[1] = 1;
		while(n < MAXN) {
			for (int i=0; i<6; ++i) {
				for (int j=(i == 1? 1 : 0); j<dist; ++j) {
					sx += dx[i];
					sy += dy[i];
					boolean [] have = new boolean[6];
					for (int k=0; k<6; ++k) {
						int tx = sx + dx[k];
						int ty = sy + dy[k];
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
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		while(tc-- > 0) {
			n = in.nextInt();
			System.out.println(tiles[n]);
		}
	}
}
