#include <bits/stdc++.h>
using namespace std;
long long m, n, i, imm, imx, tmm, dmm, tmx, dmx, res;
long long mm[1000000], mx[1000000], u[1000000], v[1000000];
main()
{
     cin>>n>>m;
     cin>>u[1];
     imm = 1;
     imx = 1;
     for (i = 2; i<=m; i++)
     {
          cin>>u[i];
          if (u[i] < u[imm])  imm = i;
          if (u[i] > u[imx]) imx = i;
     }
     for (i =1; i<=n; i++)
        cin>>v[i];
     dmm = 1;
     tmm = 1;
     dmx = 1;
     tmx = 1;
     for (i = 1; i<m; i++)
     {
          while (v[mm[tmm]] >= v[i]&&tmm >= dmm) tmm--;
          tmm++;
          mm[tmm] = i;
          while (v[mx[tmx]] <= v[i]&&tmx >= dmx) tmx--;
          tmx++;
          mx[tmx] = i;
     }
     for (i =m; i<=n; i++)
     {
          if (mm[dmm] <= i - m)
            dmm++;
          if (mx[dmx] <= i - m)
          dmx++;
          while (v[mm[tmm]] >= v[i]&&tmm >= dmm)
          tmm--;
          tmm++;
          mm[tmm] = i;
          while (v[mx[tmx]] <= v[i]&&tmx >= dmx) tmx--;
          tmx++;
          mx[tmx] = i;
          if (mm[dmm] - i + m == imm&&mx[dmx] - i + m == imx&&(v[i - m + 1] - v[i]) * (u[1] - u[m]) > 0) res++;
     }
     cout<<res;
}
