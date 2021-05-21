#include <bits/stdc++.h>
long long a[100000],b[100000],c[100000][100000];
bool kt[100000];
using namespace std;
int main(){
	long long n,m,res=0;
	cin>>n>>m;
	bool ok=false;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		if (a[i]==1) ok=true;
	}
	for (int i=1;i<=n;i++){
		kt[i]=0;
		if (i==1) c[i][1]=1,c[i][2]=0;
		else c[i][1]=0,c[i][2]=1;
	}
	if (ok==false){
		cout<<1;
		return 0;
	}
	for (int i=1;i<=m;i++){
		if (c[a[i]][1]==1 && c[a[i]][2]==0){
			c[a[i]][1]=0;
			c[b[i]][1]=1;
		}
		else if (c[a[i]][1]==0 && c[a[i]][2]>0){
			c[a[i]][2]--;
			a[b[i]][2]++;
		}
		else if (c[a[i]][1]==1 && c[a[i]][2]>0){
			
		}
		
	}
	cout<<res;
	return 0;
}
