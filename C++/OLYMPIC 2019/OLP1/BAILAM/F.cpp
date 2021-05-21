#include <bits/stdc++.h>
using namespace std;
long long a[100000000];
int main(){
	long long n,m,x,y;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>x>>y;
		a[x]++;
		a[y]++;
	}
	for (int i=1;i<=n;i++) 
		if (a[i]%2==1){
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
	return 0;
}
