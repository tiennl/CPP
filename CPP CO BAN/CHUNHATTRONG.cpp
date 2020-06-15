#include <iostream>
#include <math.h>
using namespace std;
main(){
	int m,n;
	cin>>m>>n;
	for (int i=0;i<m;i++){
		for  (int j=0;j<n;j++)
		 	if (i==0 || i==m-1 || j==0 || j==n-1) cout<<"*";
		 	else cout<<" ";
		cout<<endl;
	}
}
