#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>

int main()
{
  int n, e, p;
  std::cin >> n >> e >> p;
  std::vector<double> xs;
  std::vector<double> ys;
  for(int i=0; i<n; i++)
    {
      double x, y;
      std::cin >> x >> y;
      xs.push_back(x);
      ys.push_back(y);
    }
  double *adj = new double[n*n];
  for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
	{
	  adj[i*n + j] = std::sqrt( (xs[i]-xs[j])*(xs[i]-xs[j]) + (ys[i]-ys[j])*(ys[i]-ys[j]) );
	}
    }
  for(int i=0; i<p; i++)
    {
      int a,b;
      std::cin >> a >> b;
      a--;
      b--;
      adj[a*n + b] = 0;
      adj[b*n + a] = 0;
    }

  struct Visit
  {
    int node;
    double cost;
    bool operator<(const Visit &other) const
    {
      return cost > other.cost;
    }
  };

  std::vector<bool> visited(n,false);
  std::priority_queue<Visit> q;
  for(int i=0; i<e; i++)
    {
      q.push(Visit{i, 0.0});
    }

  double tot = 0;
  while(!q.empty())
    {
      Visit next = q.top();
      q.pop();
      if(visited[next.node])
	continue;
      visited[next.node] = true;
      tot += next.cost;
      for(int i=0; i<n; i++)
	{
	  if(visited[i])
	    continue;
	  q.push(Visit{i, adj[next.node*n+i]});
	}
    }
      
  std::cout << std::setprecision(30) << tot << std::endl;
  delete[] adj;
}
