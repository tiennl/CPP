#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	long long n,m,maxx=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			a[i+j]++;
			maxx=max(maxx,a[i+j]);
		}
	for (int i=1;i<=n+m;i++) 
		if (a[i]==maxx) cout<<i<<endl;
	return 0;
}
