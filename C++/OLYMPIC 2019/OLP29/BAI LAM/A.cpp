#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll** a;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,sum=0,maxx=0,res=0;
	cin>>n;
	a=new ll*[n];
	for (int i=0;i<n;i++) a[i]=new ll[11];
	for (int i=0;i<n;i++)
		for (int j=0;j<11;j++) cin>>a[i][j];
	for (int i=0;i<n-2;i++)
		for (int j=i+1;j<n-1;j++)
			for (int k=j+1;k<n;k++){
				maxx=0;
				sum=0;
				for (int h=0;h<11;h++){
					maxx=0;
					maxx=max(maxx,a[i][h]);
					maxx=max(maxx,a[j][h]);
					maxx=max(maxx,a[k][h]);
					sum+=maxx;
				}
				res=max(res,sum);
			}
	cout<<res;
	return 0;
}
