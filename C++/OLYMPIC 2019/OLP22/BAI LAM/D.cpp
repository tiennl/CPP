#include <bits/stdc++.h>
long long h[100000],c[100000];
using namespace std;
int main(){
	long long n,m,k,x,y,hang=0,cot=0;
	cin>>n>>m>>k;
	for (int i=0;i<k;i++){
		cin>>x>>y;
		h[x]=1;
		c[y]=1;
	}
	for (int i=1;i<=n;i++)
		if (h[i]==1) hang++;
	for (int i=1;i<=m;i++)
		if (c[i]==1) cot++;
	cout<<hang*cot;
	return 0;
}
