#include<bits/stdc++.h>
#define N 17
#define llong long long
#define _pair pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int n, nn;
int a[N][N];
_pair pos[N*N];
struct hdm{
    _pair p;
    int aim,cur;
    hdm(){};
    hdm(_pair p, int aim, int cur): p(p), aim(aim), cur(cur) {};
};
queue<hdm> q;
_pair d[N*N][N*N][3];
vector<int> X[3];
vector<int> Y[3];
bool inT(int u, int v){return (u >= 1)&&(u <= n)&&(v >= 1)&&(v <= n);}
void BFS()
    {
        while (!q.empty()){
            hdm P=q.front(); q.pop();
            _pair p=P.p;
            int u=p.fi, v=p.se;
            int aim=P.aim;
            int cur=P.cur;
            int c1=d[a[u][v]][aim][cur].fi;
            int c2=d[a[u][v]][aim][cur].se;

            for (int k=0; k < X[cur].size(); k++){
                int nu=u+X[cur][k];
                int nv=v+Y[cur][k];
                if (!inT(nu,nv)) continue;
                if (a[nu][nv] == aim){
                    if (d[aim][aim+1][cur] > MP(c1+1,c2)){
                        d[aim][aim+1][cur]=MP(c1+1,c2);
                        if (aim < nn) q.push(hdm(MP(nu,nv),aim+1,cur));
                    }
                }
                else{
                    if (d[a[nu][nv]][aim][cur] > MP(c1+1,c2)){
                        d[a[nu][nv]][aim][cur]=MP(c1+1,c2);
                        q.push(hdm(MP(nu,nv),aim,cur));
                    }
                }
            }
            for (int ncur=0; ncur < 3; ncur++)
                if (ncur != cur)
                    if (d[a[u][v]][aim][ncur] > MP(c1+1,c2+1)){
                        d[a[u][v]][aim][ncur]=MP(c1+1,c2+1);
                        q.push(hdm(MP(u,v),aim,ncur));
                    }
        }
    }
int main()
{
    cin>>n;
    for (int len=1; len <= n; len++){
        X[0].push_back(len), X[0].push_back(-len);
        Y[0].push_back(len), Y[0].push_back(-len);

        X[0].push_back(len), X[0].push_back(-len);
        Y[0].push_back(-len), Y[0].push_back(len);
    }

    X[1].push_back(-2), X[1].push_back(-2);
    Y[1].push_back(-1), Y[1].push_back(1);
    X[1].push_back(-1), X[1].push_back(-1);
    Y[1].push_back(-2), Y[1].push_back(2);

    X[1].push_back(2), X[1].push_back(2);
    Y[1].push_back(-1), Y[1].push_back(1);
    X[1].push_back(1), X[1].push_back(1);
    Y[1].push_back(-2), Y[1].push_back(2);

    for (int len=1; len <= n; len++){
        X[2].push_back(len), X[2].push_back(-len);
        Y[2].push_back(0), Y[2].push_back(0);

        X[2].push_back(0), X[2].push_back(0);
        Y[2].push_back(len), Y[2].push_back(-len);
    }
    nn=n*n;
    for (int i=1; i <= n; i++)
        for (int j=1; j <= n; j++){
            cin>>a[i][j];
            pos[a[i][j]]=MP(i,j);
        }

    for (int i=1; i <= nn; i++)
        for (int j=1; j <= nn+1; j++)
            for (int c=0; c < 3; c++)
                d[i][j][c]=MP(N*N*N,N*N*N);
    for (int i=0; i < 3; i++){
        d[1][2][i]=MP(0,0);
        q.push(hdm(pos[1],2,i));
    }
    BFS();
    int rs1=d[nn][nn+1][0].fi, rs2=d[nn][nn+1][0].se;
    for (int i=1; i < 3; i++){
        if (rs1 == d[nn][nn+1][i].fi)
            rs2=min(rs2,d[nn][nn+1][i].se);
        if (rs1 > d[nn][nn+1][i].fi)
            rs1=d[nn][nn+1][i].fi,
            rs2=d[nn][nn+1][i].se;
    }
    cout<<rs1<<' '<<rs2;
    return 0;
}
