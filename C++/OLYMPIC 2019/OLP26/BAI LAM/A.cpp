#include <bits/stdc++.h>
long long a[1000][1000],res[1000][1000];
using namespace std;
int main(){
	long long n,m,sum=0,maxr=0,maxc=0,pos=0;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		maxr=0;
		pos=0;
		for (int j=0;j<m;j++){
			cin>>a[i][j];
			sum+=a[i][j];
			if (a[i][j]>maxr){
				maxr=a[i][j];
				pos=j;
			}
		}
		sum-=a[i][pos];
		res[i][pos]=-1;
	}
	for (int j=0;j<m;j++){
		maxc=0;
		pos=0;
		for (int i=0;i<n;i++)
			if (a[i][j]>maxc){
				maxc=a[i][j];
				pos=i;
			}
		if (res[pos][j]!=-1) sum-=a[pos][j];
		res[pos][j]=-1;
	}
	cout<<sum;
	return 0;
}
/*
4 4
1 2 4 6
16 9 13 11
5 10 8 15
12 14 7 3

72
*/

