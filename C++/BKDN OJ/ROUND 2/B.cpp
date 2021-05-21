#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
char a[100][100];
ll coun[100]={0};
int main(){
	FIO
	ll m,n;
	cin>>m>>n;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) cin>>a[i][j];
	for (int i=0;i<m-1;i++)
		for (int j=0;j<n-1;j++){
			int thang=0,cham=0,x=0;
			if (a[i][j]=='#') thang++;else if (a[i][j]=='.') cham++;else x++;
			if (a[i][j+1]=='#') thang++;else if (a[i][j+1]=='.') cham++;else x++;
			if (a[i+1][j]=='#') thang++;else if (a[i+1][j]=='.') cham++;else x++;
			if (a[i+1][j+1]=='#') thang++;else if (a[i+1][j+1]=='.') cham++;else x++;
			if (thang==0) coun[x]++;
		}
	for (int i=0;i<5;i++) cout<<coun[i]<<endl;
	return 0;
}
