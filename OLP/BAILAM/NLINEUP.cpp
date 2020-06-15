#include<bits/stdc++.h>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,b,a) for(int i=b;i>=a;i--)
using namespace std;
int n;
const int N=3*1e4+1;
int a[N],d[N][4];
int main(){
    //freopen("task.inp","r",stdin);
    //freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n;
    foru(i,1,n) cin>>a[i];
    ford(i,n,1)
        foru(j,1,3) {
            d[i][j]=d[i+1][1];
            foru(k,2,j) d[i][j]=min(d[i][j],d[i+1][k]);
            if (a[i]!=j) d[i][j]++;
        }
    cout<<min(d[1][1],min(d[1][2],d[1][3]));
    return 0;
}
