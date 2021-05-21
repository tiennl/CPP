#include<bits/stdc++.h>
#define llong long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int mx=0, zz=0;
        for (int i=1; i <= n; i++){
            int x; cin>>x;
            zz=__gcd(zz,x);
            mx=max(mx,x);
        }
        zz=mx/zz - n;
        if (zz%2){
            cout<<"DD";
        }
        else{
            cout<<"M";
        }
        cout<<'\n';
    }
    return 0;
}
