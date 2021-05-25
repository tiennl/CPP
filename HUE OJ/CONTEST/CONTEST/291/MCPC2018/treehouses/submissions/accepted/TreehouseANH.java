/*  Kruskal
Extra vertex for open space
0 distance to trees nearby (first e of them)
start with gopmetric distances,
change to 0 for existing cables

*/


import java.util.*;
import java.lang.Math;

public class TreehouseANH
{
    private static int[] parent, rank;  // for intree 

    static int find(int i) {// find root with compression
      if (parent[i] != i) {
        parent[i] = find(parent[i]);
      }
      return parent[i];
    }

    static void join(int i, int j) // both roots
    {
      if (rank[i] > rank[j])
        parent[j] = i;
      else if (rank[j] >= rank[i]) {
         parent[i] = j;
         if (rank[j] == rank[i])
             rank[j]++;
      }
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int e = in.nextInt();
        int p = in.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];
        Edge[] edges = new Edge[n*(n-1)/2+e];
        for (int k = 0; k < n; k++) {
            x[k] = in.nextDouble();
            y[k] = in.nextDouble();
        }
        double[][] dist = new double[n][n];
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
              double dx = x[i] - x[j], dy = y[i] - y[j];
              dist[j][i] = Math.sqrt(dx*dx + dy*dy);
            }
        for (int k = 0; k < p; k++)
          dist[in.nextInt()-1][in.nextInt()-1] = 0;
        int ei = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) 
              edges[ei++] = new Edge(dist[j][i], i, j);
        for (int k = 0; k < e; k++)  // free connect to open space
           edges[ei++] = new Edge(0, k, n);
        Arrays.sort(edges);
        rank = new int[n+1]; // extra for open space
        parent = new int[n+1];
        for (int i = 0; i <= n; i++)
           parent[i] = i;
        ei = 0;
        double totLen = 0;
        int edgesLeft = n; // n tree houses, one open space
        while (edgesLeft > 0) {
            Edge edge = edges[ei++];
            int i = find(edge.i), j = find(edge.j);
            if (i != j) {
              join(i, j);
              totLen += edge.d;
              edgesLeft--;
            }
        }
        System.out.println(totLen);
    } //main

}

    class Edge implements Comparable<Edge>
    {
      double d;
      int i, j;

      public Edge(double d_, int i_, int j_)
      {
        d = d_;
        i = i_;
        j = j_;
      }

      public int compareTo(Edge e)
      {
        return (int)Math.signum(d - e.d);
      }
    } // class Edge

