// Author: Adrian Kuegel
// Algorithm: Graham Scan
// Complexity: O(n log n)

import java.util.*;

public class simple_polygon {
	int [] x;
	int [] y;
	int DET(int a, int b, int c, int d) {
		return a * d - b * c;
	}
	class PointComparator implements Comparator<Integer> {
		public int compare(Integer a2, Integer b2) {
			int a = a2.intValue();
			int b = b2.intValue();
			if (x[a] != x[b])
				return x[a] - x[b];
			return y[a] - y[b];
		}
	}
	simple_polygon() {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		Comparator<Integer> comp = new PointComparator();
		while(tc-- > 0) {
			int n = in.nextInt();
			x = new int[n];
			y = new int[n];
			Integer [] sind = new Integer[n];
			for (int i=0; i<n; ++i) {
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				sind[i] = new Integer(i);
			}
			Arrays.sort(sind, comp);
			int [] ind = new int[n];
			for (int i=0; i<n; ++i)
				ind[i] = sind[i].intValue();
			int [] ch = new int[n];
			int l = 1;
			ch[0] = ind[0];
			ch[1] = ind[1];
			for (int i=2; i<n; ++i) {
				while(l > 0 && DET(x[ch[l]]-x[ch[l-1]],x[ind[i]]-x[ch[l-1]],y[ch[l]]-y[ch[l-1]],y[ind[i]]-y[ch[l-1]]) > 0)
					--l;
				ch[++l] = ind[i];
			}
			for (int i=0; i<=l; ++i) {
				if (i > 0) System.out.print(" ");
			 	System.out.print(ch[i]);
			}
			for (int i=n-1; i>0; --i) {
				if (ch[l] == ind[i])
					--l;
				else
					System.out.print(" "+ind[i]);
			}
			System.out.println("");
		}
	}
	public static void main(String [] args) throws Exception {
		new simple_polygon();
	}
}
