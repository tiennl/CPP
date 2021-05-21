import java.util.*;

public class Moving_walter_Scanner {

  static class Data {
    int to;
    long t, sf;
    Data(int _to, long _t, long _sf) {
      to = _to;
      t = _t;
      sf = _sf;
    }
  }

  static Vector<Vector<Data>> adj = new Vector<Vector<Data>>();
  static Vector<Integer> result = new Vector<Integer>();
  static Vector<Long> freq = new Vector<Long>();
  static long sumfreq, cost, mincost;

  static long dfs1(int x, int p, long c) {
    long sf = freq.elementAt(x);
    cost += c * sf;
    Data jt = null;
    for (Data d : adj.elementAt(x))
      if (d.to != p)
        sf += d.sf = dfs1(d.to, x, c+d.t);
      else
        jt = d;
    if (jt != null)
      jt.sf = sumfreq-sf;
    return sf;
  }

  static void dfs2(int x, int p, long c) {
    if (c == mincost)
      result.add(x);
    else if (c < mincost) {
      mincost = c;
      result.clear();
      result.add(x);
    }
    for (Data d : adj.elementAt(x))
      if (d.to != p)
        dfs2(d.to, x, c + (sumfreq-2*d.sf)*d.t);
  }

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    for (int k = sc.nextInt() ; k>0 ; k--) {
      int n = sc.nextInt();
      adj = new Vector<Vector<Data>>();
      freq = new Vector<Long>();
      for (int i=0 ; i<=n ; i++) {
        adj.add(new Vector<Data>());
        freq.add(0l);
      }
      for (int i=0 ; i<n-1 ; i++) {
        int a = sc.nextInt(), b = sc.nextInt();
        long t = sc.nextLong();
        adj.elementAt(a).add(new Data(b, t, 0l));
        adj.elementAt(b).add(new Data(a, t, 0l));
      }
      sumfreq = 0l;
      for (int m = sc.nextInt() ; m>0 ; m--) {
        int a = sc.nextInt();
        long f = sc.nextLong();
        freq.set(a, f);
        sumfreq += f;
      }
      if (n == 1) {
        System.out.println("0");
        System.out.println("1");
        continue;
      }
      mincost = 1l<<60;
      result.clear();
      for (int i=1 ; i<=n ; i++)
        if (adj.elementAt(i).size() == 1) {
          cost = 0;
          dfs1(i, -1, 0l);
          dfs2(i, -1, cost);
          break;
        }
      Collections.sort(result);
      System.out.println(2*mincost);
      for (Iterator<Integer> it = result.iterator() ; it.hasNext() ; )
        System.out.print(it.next() + (it.hasNext() ? " " : ""));
      System.out.println();
    }
  }
}

