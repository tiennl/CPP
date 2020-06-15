#include <iostream>
using namespace std;
int a[250][250];
int s[250][250];
main(){
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			cin>>a[i][j];}
	for (int i=0;i<n;i++) s[0][i]=a[0][i]+s[0][i-1];
	for (int i=0;i<m;i++) s[i][0]=a[i][0]+s[i-1][0];
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++)
		    cout<<s[i][j]<<" ";
		cout<<endl;
    }		
}
