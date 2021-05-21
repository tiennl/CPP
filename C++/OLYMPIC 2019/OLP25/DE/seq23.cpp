#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
using   namespace   std;
int n,Q,K,maxb[100005];
struct  data
{
    int a,b;
}x[100005];
int L[100005],R[100005];
int dau,cuoi,mid,ans;
//--------------------------
void    read()
{
    scanf("%d%d",&n,&Q);
    fo(i,1,n) scanf("%d",&x[i].a);
}
//--------------------------
void    LeftRight()
{
    fo(i,1,n)
    {
        L[i]=i-1;
        while (L[i]>0 && x[L[i]].a<=x[i].a) L[i]=L[L[i]];
    }
    fd(i,n,1)
    {
        R[i]=i+1;
        while (R[i]<=n && x[R[i]].a<=x[i].a) R[i]=R[R[i]];
    }
}
//--------------------------
bool    cmp(data A,data B)
{
    return (A.a<B.a);
}
//--------------------------
void    solve()
{
    read();
    LeftRight();
    fo(i,1,n) x[i].b=R[i]-L[i]-1;
    sort(x+1,x+n+1,cmp);
    maxb[0]=-1e9-1;
    fo(i,1,n) maxb[i]=max(maxb[i-1],x[i].b);
    maxb[0]=0;
    while (Q--)
    {
        scanf("%d",&K);
        dau=1;cuoi=n;ans=0;
        while (dau<=cuoi)
        {
            mid=(dau+cuoi)/2;
            if (x[mid].a<=K)
            {
                ans=mid;
                dau=mid+1;
            }
            else cuoi=mid-1;
        }
        printf("%d\n",maxb[ans]);
    }
}
//--------------------------
int     main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    freopen("seq23.inp","r",stdin);
    freopen("seq23.out","w",stdout);
    solve();
}

