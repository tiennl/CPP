#include <bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],c[1000000],d[1000000];
int check[1000000];
int main(){
	unsigned long long n,m,res=10e18,ans=0;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i]>>b[i];
	for (int i=0;i<m;i++){
		cin>>c[i]>>d[i];
		check[i]=0;
	}
	for (int i=0;i<n;i++){
		ans=0;
		res=10e18;
		for (int j=0;j<m;j++){
			if (check[j]==0)
				if ((abs(a[i]-c[j])+abs(b[i]-d[j]))<res){
					res=abs(a[i]-c[j])+abs(b[i]-d[j]);
					ans=j+1;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
