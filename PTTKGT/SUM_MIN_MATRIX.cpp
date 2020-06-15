#include <iostream>
using namespace std;
int sum(int m, int n, int a[100][100]){
	int s=0;
	for (int i=0;i<m;i++){
		int r=a[i][0];
		for (int j=1;j<n;j++) r=min(r,a[i][j]);
		s+=r;
	}
	return s;
}
int main(){
	int m=3,n=4;
	int a[100][100]={{3,1,2,9},
					{7,6,4,8},
					{5,3,9,7}};
	cout<<sum(m,n,a);
	return 0;
}
