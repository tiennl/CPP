#include <bits/stdc++.h>
int a[100000][100000];
using namespace std;
int main(){
	long long n,m;
	cin>>n;
	m=n;
	cout<<m;
/*	a[0][0]='b';
	for (int i=0;i<=n;i+=3) a[0][i]='b',a[i][0]='b'; 
	for (int i=0;i>=m;i-=3) a[0][i]='b',a[i][0]='b';
	for (int i=0;i>=m;i--){
		for (int j=0;j>m;j--)
			if (a[i+1][j-1]=='b' || a[i+1][j+2]=='b') a[i][j]='b';
		for (int j=0;j<=n;j++)
			if (a[i+1][j+1]=='b' || a[i+1][j-2]=='b') a[i][j]='b';	
	}
	for (int i=0;i<n;i++){
		for (int j=0;j>=m;j--)
			if (a[i-1][j-1]=='b' || a[i-1][j+2]=='b') a[i][j]='b';
		for (int j=0;j<=n;j++)
			if (a[i-1][j+1]=='b' || a[i-1][j-2]=='b') a[i][j]='b';
	}
	for (int i=m;i<=n;i++){
		for (int j=m;j<=n;j++)
			if (a[i][j]=='b') cout<<"b";
			else cout<<"w";
		cout<<endl;
	}*/
	return 0;
}
