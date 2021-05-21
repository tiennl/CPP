#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long a[1000][1000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,m,dem=0,res=0,d1,d2,d3,d4;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) cin>>a[i][j];
	for (int i=0;i<n-1;i++)
		for (int j=0;j<m-1;j++){
			d1=a[i][j];
			d2=a[i][j+1];
			d3=a[i+1][j];
			d4=a[i+1][j+1];
			if (abs(d1-d2)%3==0 || abs(d1-d3)%3==0 || abs(d1-d4)%3==0 || 
			    abs(d2-d3)%3==0 || abs(d2-d4)%3==0 || abs(d3-d4)%3==0) res++;
		}
	cout<<res;
	return 0;
}
