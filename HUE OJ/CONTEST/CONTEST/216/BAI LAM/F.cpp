#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long t,n,m1,m2,m3,d,res=0;
	cin>>t;
	while (t--){
		cin>>n>>m1>>m2>>m3>>d;
		for (int i=1;i<=n;i++) a[i]=0;
		a[m1]=1;
		a[m2]=1;
		a[m3]=1;
		res=0;
		for (int j=0;j<d;j++)
			for (int i=1;i<=n;i++)
				if (a[i]==1){
					a[i-1]=1;
					if (a[i+1]==0){
						i++;
						a[i]=1;
					}
					else a[i+1]=1;
				}
		for (int i=1;i<=n;i++) 
			if (a[i]==0) res++;
		cout<<res<<endl;
	}
	return 0;
}
