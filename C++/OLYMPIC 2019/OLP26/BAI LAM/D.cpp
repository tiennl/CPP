#include <bits/stdc++.h>
long long a[1000000],b[1000000],aa[10000][10000],bb[10000][10000];
using namespace std;
int main(){
	long long n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++) aa[i][j]=a[i]+a[j];
	for (int i=0;i<n-1;i++){
		bb[i][i]=b[i];
		for (int j=i+1;j<n;j++){
			bb[i][j]=min(bb[i][j-1],b[j]);
			res=max(res,min(bb[i][j],aa[i][j]));
		}
	}
	cout<<res;
	return 0;
}
