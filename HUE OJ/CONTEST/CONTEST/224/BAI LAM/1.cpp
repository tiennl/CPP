#include <bits/stdc++.h>
int a[1000][1000];
using namespace std;
int main(){
	int n,m,x,y;
	float bac=0;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	if (n==1){
		cout<<"YES";
		return 0;
	}
	float nn=((float)n)/2;
	for (int i=1;i<=n;i++){
		bac=0;
		for (int j=1;j<=n;j++)
			if (j!=i && a[i][j]==1) bac++;
		if (bac<nn){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
