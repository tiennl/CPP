#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,q;
int a[N];
int main()
{
    /*freopen("MAXIMUM.inp","r",stdin);
    freopen("MAXIMUM.out","w",stdout);*/
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>q;
    a[0]=-1;
    for (int i=1; i <= n; i++)
        cin>>a[i];
    while (q--){
        int l,r,val; cin>>l>>r>>val;
        int id=lower_bound(a+l,a+1+r,val) - a;
        if ((id < l)||(r < id)||(a[id] < val)){
            id=0;
        }
        cout<<a[id]<<'\n';
    }
    return 0;
}
