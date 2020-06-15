#include <iostream>
using namespace std;
long long a[10000][10000];
int main(){
	int m,n;
	long long s=0;
	cin>>m>>n;
	for (int i=0;i<m;i++){
		s=0;
		for (int j=0;j<n;j++){
			cin>>a[i][j];
			s+=a[i][j];
		}
		cout<<s<<" ";
	}
	return 0;
}
