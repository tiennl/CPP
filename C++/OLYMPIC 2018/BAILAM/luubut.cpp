#include <iostream>
using namespace std;
int a[1000000];
int s[1000000];
main(){
	int n,dem;
	cin>>n;
	dem=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if ((s[a[i]])==0){
			dem++;
			s[a[i]]=1;
	    }
		else s[a[i]]=1;
	}
	cout<<dem;
}

