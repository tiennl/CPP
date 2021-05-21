#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000],b[10109999];
int main(){
    ll k,s=0;
    cin>>k;
    for (int i=10102010;i<=10109999;i++) b[i]=0; 
    for (int i=0;i<k;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for (int i=10102010;i<=10109999;i++)
        if (b[i]>0){
            if (b[i]<=5) s+=100;
            else if (b[i]>5) s+=(100+(b[i]-5));
        }
    cout<<s;
    return 0;
}
