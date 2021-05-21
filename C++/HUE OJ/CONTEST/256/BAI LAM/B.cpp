#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll n,m,res=0,c=0;
ll x[100],d[100],a[100][100];
void check(){
	c=0;
	if (x[1]==1){
		for (int i=1;i<n;i++)
			if (a[x[i]][x[i+1]]==1) c++;
		if (c==n-1) res++;  
	}
}
void permu(ll i){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==n) check();
			else permu(i+1);
			d[j]=0;
		}
}
int main(){
	FIO
	cin>>n>>m;
	for (int i=0;i<m;i++){
		ll t1,t2;
		cin>>t1>>t2;
		a[t1][t2]=1;
		a[t2][t1]=1;
	}
	permu(1);
	cout<<res;
	return 0;
}
