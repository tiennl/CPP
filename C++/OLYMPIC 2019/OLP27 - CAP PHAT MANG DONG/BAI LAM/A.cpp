#include <bits/stdc++.h>
long long** a,** res;
using namespace std;
int main(){
	long long n,m,sum=0,maxr=0,maxc=0,pos=0;
	cin>>n>>m;
	a=new long long*[n];
	res=new long long*[n];
	for (int i=0;i<n;i++) a[i]=new long long[m];
	for (int i=0;i<n;i++) res[i]=new long long[m];
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
