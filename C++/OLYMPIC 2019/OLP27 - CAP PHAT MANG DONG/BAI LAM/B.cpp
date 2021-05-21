#include <bits/stdc++.h>
long long a[1000][1000];
long long col[10000],row[10000];
using namespace std;
int main(){
	long long c,n,m=0,x,y;
	cin>>c>>n;
//	a=new long long*[n+1];
//	for (int i=0;i<n;i++) a[i]=new long long[n+1];
	for (int i=0;i<n;i++){
		cin>>x>>y;
		m=max(m,x);
		m=max(m,y);
		a[x][y]=1;
	}
	m++;
	for (int i=0;i<m;i++){
		row[i]=0;
		for (int j=0;j<m;j++)
			if (a[i][j]==1) row[i]++;
	}
	for (int j=0;j<m;j++){
		col[j]=0;
		for (int i=0;i<m;i++)
			if (a[i][j]==1) col[j]++;
	}
	for (int i=0;i<m-1;i++){
		
		for (int j=i;j<m;j++)
	return 0;
}
