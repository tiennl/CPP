/* Solution to "Wormholes" from NWERC 2009
 *
 * Author: Per Austrin
 *
 * This solution is also Omega(n^4) but it takes a bit of effort to
 * trigger that behaviour.
 * 
 * "Translated" to Java by Tobias Werth
 */

import java.io.*;
import java.util.*;

public class meisterT {

	public static final int inf = 1<<25;

	public static int N;
	public static int dist[][] = new int[110][110];
	public static int shift[] = new int[110];
	public static int avail[] = new int[110];
	public static int mintime[] = new int[110];

	public static double sqr(double x) { return x*x; }

	public static int bellman_ford(int src, int startt) {
		int back[] = new int[200];
		for (int i = 0; i < N; ++i) {
			mintime[i] = startt + dist[src][i];
			back[i] = -1;
		}
		back[src] = src;
		for (int i = 0; i <= N; ++i)
			for (int u = 0; u < N; ++u)
				for (int v = 0; v < N; ++v) {
					int nt = mintime[u] + dist[u][v];
					if (u >= 2 && u % 2 == 0 && v == u+1)
						nt = Math.min(nt, Math.max(mintime[u], avail[u]) + shift[u]);
					if (nt < mintime[v]) {
						mintime[v] = nt;
						back[v] = u;
						if (i == N) {
							while (back[u] != -1) {
								v = back[u];
								back[u] = -1;
								 u = v;
							}
							return u;
						}
					}
				}
		return -1;
	}

	public static int LO;

	public static int besttime(int u) {
		int lo = LO-1, hi = mintime[u];
		while (hi - lo > 1) {
			int m = (lo+hi)/2+1;
			bellman_ford(u, m);
			if (mintime[u] < m) hi = mintime[u];
			else lo = m-1;
		}
		return hi;
	}

	public static void solve() throws Exception {
		int n;
		int x[] = new int[200];
		int y[] = new int[200];
		int z[] = new int[200];
		
		x[0] = sc.nextInt();
		y[0] = sc.nextInt();
		z[0] = sc.nextInt();
		x[1] = sc.nextInt();
		y[1] = sc.nextInt();
		z[1] = sc.nextInt();
		n = sc.nextInt();
		N = 2*n+2;
		for (int i = 2; i < N; i += 2) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			z[i] = sc.nextInt();
			x[i + 1] = sc.nextInt();
			y[i + 1] = sc.nextInt();
			z[i + 1] = sc.nextInt();
			avail[i] = sc.nextInt();
			shift[i] = sc.nextInt();
			LO = Math.min(LO, avail[i]+shift[i]);
		}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				double d = Math.sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]) + sqr(z[i]-z[j]));
				dist[i][j] = (int)(Math.ceil(d)+0.01);
			}

		int v = bellman_ford(0, 0);
		while (v != -1) {
			int t = besttime(v);
			v = bellman_ford(v, t);
		}
		System.out.printf("%d\n", mintime[1]);
	}

	public static Scanner sc;

	public static void main(String[] args) throws Exception {
		sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; ++i) solve();
	}
}
