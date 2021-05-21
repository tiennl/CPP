#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,a,b)  for(int i=a;i<b;++i)
#define fore(i,a)  for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define TASK "SEQ49"
#define a   first
#define b   second
using   namespace   std;
typedef pair<int,int> ii;
int n,k,ans,F[100005];
ii  x[100005];
//--------------------------
void    readf(){
    cin>>n>>k;
    fo(i,1,n) cin>>x[i].a;
    fo(i,1,n) cin>>x[i].b;
    sort(x+1,x+n+1,greater<ii>());
}
//--------------------------
void    solve(){
    F[1]=x[1].b;
    fo(i,2,n) F[i]=max(F[i-1],x[i].b);
    ans=0;
    fo(i,k,n) ans=max(ans,x[i].a+F[i]);
    cout<<ans<<"\n";
}
//--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    readf();
    solve();
}



