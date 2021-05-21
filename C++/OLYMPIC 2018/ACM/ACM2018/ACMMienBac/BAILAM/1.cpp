#include <iostream>
using namespace std;
int a[10];
main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	if (n==0) cout<<"48";
	if (n==1) cout<<"35";
	if (n==2){
		if (a[0]==a[1]) cout<<"35"<<endl<<"35";
		if (a[0]!=a[1]) cout<<"35"<<endl<<"26";
	}
	if (n==3){
		if (a[0]==a[1] && a[1]==a[2]) cout<<"35"<<endl<<"35"<<endl<<"35";
		if (a[0]!=a[1] && a[1]!=a[2] && a[0]!=a[2]) cout<<"35"<<endl<<"26"<<endl<<"18";
		if (a[0]==a[1] && a[1]!=a[2]) cout<<"35"<<endl<<"35"<<endl<<"26";
		if (a[0]!=a[1] && a[1]==a[2]) cout<<"35"<<endl<<"26"<<endl<<"26";
		if (a[0]==a[2] && a[1]!=a[2]) cout<<"35"<<endl<<"26"<<endl<<"26";	
	}
}
