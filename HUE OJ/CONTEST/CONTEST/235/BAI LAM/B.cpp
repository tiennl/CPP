#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000],b[1000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n,m1,m2,m3,d,res=0;
	cin>>t;
	while (t--){
		cin>>n>>m1>>m2>>m3>>d;
		for (int i=1;i<=n;i++) a[i]=0;
		a[m1]=1;
		a[m2]=1;
		a[m3]=1;
		res=0;
		while (d--){
			int k=-1;
			for (int i=1;i<=n;i++)
				if (a[i]==1){
					k++;
					b[k]=i-1;
					k++;
					b[k]=i+1;
				}
			k++;
			for (int i=0;i<k;i++) a[b[i]]=1,b[i]=0;
		}
		for (int i=1;i<=n;i++)
			if (a[i]==0) res++;
		cout<<res<<endl;
	}
	return 0;
}
