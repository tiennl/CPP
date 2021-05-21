#include <iostream>
using namespace std;
long long a[50][50];
int main(){
	long long n;
	cin>>n;
	a[1][1]=a[2][1]=a[2][2]=1;
	if (n>=1) cout<<1<<endl;
	if (n>=2) cout<<1<<" "<<1<<endl;
	for (int i=3;i<=n+1;i++){
		for (int j=1;j<=i;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
