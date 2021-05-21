#include <bits/stdc++.h>
int a[1000][1000];
using namespace std;
int main(){
	long long n,m;
	cin>>n;
	m=n*(-1);
	a[0][0]=1;
	for (int i=0;i<=n;i+=3){
		a[0][i]=1;
		a[i][0]=1;
	}
	for (int i=0;i>=m;i-=3){
		a[0][i]=1;
		a[i][0]=1;
	}
	for (int i=-1;i>=m;i--){
		for (int j=-1;j>=m;j--) 
			if ((a[i+1][j-1]==1 && j>m && i<n) || a[i+1][j+2]==1) a[i][j]=1;
		for (int j=1;j<=n;j++) cout<<i<<" "<<j<<endl;
			if ((a[i+1][j+1]==1 && i<n && j<n) || (a[i+1][j-2]==1 && j>m+1)) a[i][j]=1;	
	}
/*	for (int i=0;i<n;i++){
		for (int j=0;j>m;j--)
			if (a[i-1][j-1]==1 || a[i-1][j+2]==1) a[i][j]=1;
		for (int j=0;j<=n;j++)
			if (a[i-1][j+1]==1 || a[i-1][j-2]==1) a[i][j]=1;
	}*/
	for (int i=m;i<=n;i++){
		for (int j=m;j<=n;j++)
			if (a[i][j]==1) cout<<"b";
			else cout<<"w";
		cout<<endl;
	}
	return 0;
}
