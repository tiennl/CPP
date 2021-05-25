#include <bits/stdc++.h>
char a[10000][10000];
using namespace std;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) cin>>a[i][j];
	for (int i=0;i<m;i++){
		for (int j=0;j<k;j++){
			for (int h=0;h<n;h++)
				for (int l=0;l<k;l++) cout<<a[i][h];
			cout<<endl;
		}
	}
	return 0;
}
