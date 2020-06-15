#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N],b[N];

int main(){
	FIO
	ll t,n,m1,m2,m3,d;
	cin>>t;
	while (t--){
		ll res=0;
		cin>>n>>m1>>m2>>m3>>d;
		for (int i=1;i<=n;i++) a[i]=0,b[i]=0;
		a[m1]=1;
		a[m2]=1;
		a[m3]=1;
		while (d--){
			for (int i=1;i<=n;i++)
				if (a[i]==1) b[i-1]=1,b[i]=1,b[i+1]=1;
			for (int i=1;i<=n;i++) a[i]=b[i];
		}
		for (int i=1;i<=n;i++) 
			if (a[i]==0) res++;
		cout<<res<<endl;
	}
	return 0;
}
