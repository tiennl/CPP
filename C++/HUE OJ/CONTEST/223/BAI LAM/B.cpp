#include <bits/stdc++.h>
int a[1000];
using namespace std;
int main(){
	int n,m,x,y;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>x>>y;
		a[x]++;
		a[y]++;
	}
	for (int i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}
