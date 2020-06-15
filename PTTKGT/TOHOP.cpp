#include <iostream>

using namespace std;

int f[1000][1000];

int C1(int n, int k){
	if (k==0 || k==n) return 1;
	return C1(n-1,k-1)+C1(n-1,k);
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<C1(n,k)<<endl;
	for (int i=0;i<=n;i++) f[i][0]=1,f[i][i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++) f[i][j]=f[i-1][j]+f[i-1][j-1];
	cout<<f[n][k];
	return 0;
}
