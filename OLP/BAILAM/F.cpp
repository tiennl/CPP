#include <iostream>
int a[10000][10000];
using namespace std;
main(){
	int n,m,x,y;
	long long dem;
	cin>>n>>m;
	for (int i=0;i<n;i++) 
		for (int j=0;j<n;j++) 
		    a[i][j]=0;
	for (int i=0;i<m;i++){
		cin>>x>>y;
		a[x][y]=1;	
		a[y][x]=1;
		dem=0;
		for (int d1=0;d1<n-2;d1++)
			for (int d2=d1+1;d2<n-1;d2++)
				for (int d3=d2+1;d3<n;d3++)
					if ((a[d1][d2]==0 && a[d2][d3]==0 && a[d1][d3]==0) || (a[d1][d2]==1 && a[d2][d3]==1 && a[d1][d3]==1)) dem++;
		cout<<dem<<endl;
	}
}
