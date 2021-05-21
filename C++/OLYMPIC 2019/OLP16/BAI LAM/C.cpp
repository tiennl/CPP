#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,k,res=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<long long>());
    long long i=1;
    while (i<=n){
        res+=(a[i]-1)*2;
        i+=k;
    }
    cout<<res;
    return 0;
}
