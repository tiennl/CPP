#include <bits/stdc++.h>
using namespace std;
double a[10000000];
long long b[100000000],f[100000000] ;
int main(){
	long long n,m=0;
    cin>>n;
    for (int i=1;i<=n;i++){
		cin>>a[i];
		b[(long long)(a[i])]++;
		if (b[(long long)(a[i])]>1) a[i]=a[i]+0.001*b[(long long)(a[i])];
	}
    for (int i=1;i<=n;i++){
        f[i]=lower_bound(b+1,b+1+m,a[i])-b;
        m=max(m,f[i]);
        b[f[i]]=a[i];
    }
    cout<<n-m;
    return 0;
}
