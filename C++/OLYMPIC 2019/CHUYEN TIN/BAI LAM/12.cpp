#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005

ll m,n,a[N],b[N],f[N];

int main(){
	FIO
	cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        f[i]=lower_bound(b+1,b+1+m,a[i])-b;
        m=max(m,f[i]);
        b[f[i]]=a[i];
    }
    vector <int> v;
    for (int i=n;i>=1;i--)
        if (f[i]==m){
        	v.push_back(a[i]);
            m--;
    	}
    cout<<n-v.size();
	return 0;
}
