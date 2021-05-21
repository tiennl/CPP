#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
ll n,k,m,coun=-1;
ll x[1000]; 
void pf(){
	coun++;
	if (coun==m)
	    for (int i=1;i<=k;i++) cout<<x[i]<<" ";
}
void combin(int i){
	int j;
	for (j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if (i==k) pf();
		else combin(i+1);
	}
}
int main(){
	FIO
	cin>>n>>k>>m;
	x[0]=0;
	combin(1);
	return 0;
}
