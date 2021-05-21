#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,num,res=0;
	cin>>n>>m;
	int *f=new int[m+1];
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++){
		cin>>num;
		f[num%m]++;
	}
	if (m%2==0) f[m/2]=min(f[m/2],1); 
	res=min(f[0],1);
	for (int i=1;i<=m/2;i++) 
		res+=max(f[i],f[m-i]);
	cout<<res;
	return 0;
}
