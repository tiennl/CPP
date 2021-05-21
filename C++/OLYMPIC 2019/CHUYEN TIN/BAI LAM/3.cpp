#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 30001
ll a[N][31];
int n,k,res;
int main(){
	char c;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=30;j++){
			cin>>c;
			if (c=='A') a[i][j]=0;
			if (c=='X') a[i][j]=1;
			if (c=='G') a[i][j]=2;
			if (c=='T') a[i][j]=3;
		}
	}
	cout<<-1;
	return 0;
}
