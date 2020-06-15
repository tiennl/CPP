#include <bits/stdc++.h>

using namespace std;

string x,y;
int f[1000][1000];

int l(int i, int j){
	if (i<0 || j<0) return 0;
	if (x[i]==y[j]) return 1+l(i-1,j-1);
	return max(l(i,j-1),l(i-1,j));  
} 

int main(){
	int m,n;
	cin>>x>>y;
	m=x.size();
	n=y.size();
	cout<<l(m-1,n-1)<<endl;
	// Khu de quy
	for (int i=0;i<m;i++) f[i][0]=0;
	for (int i=0;i<n;i++) f[0][i]=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (x[i]==y[j]) f[i+1][j+1]=1+f[i][j];
			else f[i+1][j+1]=max(f[i+1][j],f[i][j+1]);
	cout<<f[m][n];
	return 0;
}
// Do dai xau con chung dai nhat
/*
CEACEEC
AECECA
-> 4 (ECEC / AEEC)
*/


