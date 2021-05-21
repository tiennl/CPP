// Author: Adrian Kuegel

import java.util.*;

class room_assignments {
	static ArrayList [] adj;
	static int [] id;
	static int dfs(int cur, int cid) {
		if (id[cur] > 0)
			return 0;
		id[cur] = cid;
		int ret = adj[cur].size() - 2;
		for (Iterator it = adj[cur].iterator(); it.hasNext(); ) {
			int k = ((Integer)it.next()).intValue();
			ret += dfs(k, cid);
		}
		return ret;
	}
	public static void main(String [] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		while(tc-- > 0) {
			int n = in.nextInt();
			adj = new ArrayList[n];
			for (int i=0; i<n; ++i)
				adj[i] = new ArrayList();
			for (int i=1; i<n; ++i) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj[a].add(new Integer(b));
				adj[b].add(new Integer(a));
			}
			int [] v = new int[n];
			for (int i=0; i<n; ++i)
				v[i] = in.nextInt();
			id = new int[n];
			boolean impossible = false;
			int cid = 0, critical_component = 0;
			for (int i=0; i<n; ++i) {
				if (id[i] > 0)
					continue;
				++cid;
				if (dfs(i, cid) < 0) {
					if (critical_component > 0)
						impossible = true;
					critical_component = cid;
				}
			}
			if (impossible)
				System.out.println("impossible");
			else {
				int a = 0, b = 0, bestA = 0, bestB = 0;
				if (cid > 1) {
					for (int i=0; i<n; ++i)
						if (id[i] == critical_component && v[i] > bestA) {
							bestA = v[i];
							a = i;
						}
					for (int i=0; i<n; ++i)
						if (id[i] != critical_component
						|| (v[i] == bestA && i != a)) {
							b = i;
							break;
						}
				}
				else {
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
				if (a > b) {
					int t = a;
					a = b;
					b = t;
				}
				System.out.println((a+1) + " " + (b+1));
			}
		}
	}
}
