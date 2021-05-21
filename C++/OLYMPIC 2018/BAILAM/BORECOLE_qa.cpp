#include <bits/stdc++.h>
#define MAXN 1000002
#define maxs 30000001
using namespace std;
typedef long long int ll;
int n,r,m,a[MAXN],lazy1[4*MAXN],lazy2[4*MAXN];
struct C
{
    int gt,vt;
};
C mi[4*MAXN],ma[4*MAXN];

void Tao(int p,int l,int r)
{
    if(l == r)
    {
        mi[p].gt = a[l];
        mi[p].vt = l;
        ma[p].gt = a[l];
        ma[p].vt = l;
        return;
    }
    int m = (l+r)/2;
    Tao(p*2,l,m);
    Tao(p*2+1,m+1,r);
    if(mi[p*2].gt <= mi[p*2+1].gt)mi[p] = mi[p*2];
    else mi[p] = mi[p*2+1];
    if(ma[p*2].gt >= ma[p*2+1].gt)ma[p] = ma[p*2];
    else ma[p] = ma[p*2+1];
}
void bon(int p,int l,int r,int pl,int pr)
{
    if(lazy1[p])
    {
        ma[p].gt += lazy1[p];
        mi[p].gt += lazy1[p];
        if(pl != pr)
        {
            lazy1[p*2] = lazy1[p];
            lazy1[p*2+1] = lazy1[p];
        }
        lazy1[p] = 0;
    }
    if(lazy2[p])
    {
        ma[p].gt = 0;
        mi[p].gt = maxs;
        if(pl != pr)
        {
            lazy2[p*2] = lazy2[p];
            lazy2[p*2+1] = lazy2[p];
        }
        lazy2[p] = 0;
    }
    if(pl > r || pr < l)return;
    if(pl >= l && pr <= r)
    {
        ma[p].gt += 1;
        mi[p].gt += 1;
        if(pl!=pr)
        {
            lazy1[p*2] += 1;
            lazy1[p*2+1]+= 1;
        }
        return;
    }
    int m = (pl+pr)/2;
    bon(p*2,l,r,pl,m);
    bon(p*2+1,l,r,m+1,pr);
    if(mi[p*2].gt <= mi[p*2+1].gt)mi[p] = mi[p*2];
    else mi[p] = mi[p*2+1];
    if(ma[p*2].gt >= ma[p*2+1].gt)ma[p] = ma[p*2];
    else ma[p] = ma[p*2+1];
}
void chat(int p,int l,int r,int pl,int pr)
{
    if(lazy1[p])
    {
        ma[p].gt += lazy1[p];
        mi[p].gt += lazy1[p];
        if(pl != pr)
        {
            lazy1[p*2] = lazy1[p];
            lazy1[p*2+1] = lazy1[p];
        }
        lazy1[p] = 0;
    }
    if(lazy2[p])
    {
        ma[p].gt = 0;
        mi[p].gt = maxs;
        if(pl != pr)
        {
            lazy2[p*2] = lazy2[p];
            lazy2[p*2+1] = lazy2[p];
        }
        lazy2[p] = 0;
    }
    if(pl > r || pr < l)return;
    if(pl >= l && pr <= r)
    {
        ma[p].gt = 0;
        mi[p].gt = maxs;
        if(pl!=pr)
        {
            lazy2[p*2] = 1;
            lazy2[p*2+1] = 1;
        }
        return;
    }
    int m = (pl+pr)/2;
    chat(p*2,l,r,pl,m);
    chat(p*2+1,l,r,m+1,pr);
    if(mi[p*2].gt <= mi[p*2+1].gt)mi[p] = mi[p*2];
    else mi[p] = mi[p*2+1];
    if(ma[p*2].gt >= ma[p*2+1].gt)ma[p] = ma[p*2];
    else ma[p] = ma[p*2+1];
}
int main(){
    cin>>n>>r>>m;
    for(int i = 1; i <= n;i++)cin>>a[i];
    Tao(1,1,n);
    while(m--)
    {
        bon(1,max(1,mi[1].vt-r),min(n,mi[1].vt+r),1,n);
        chat(1,max(1,ma[1].vt-r),min(n,ma[1].vt+r),1,n);
    }
    cout<<ma[1].gt;
}
