#include <iostream>
using namespace std;
int a[50];
int s[50];
main(){
	int n;
	cin>>n;
	int dem=0;
	for (int i=0; i<n;i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
		if (a[i]>=s[i-1]) dem++;
		else{
			cout<<"FALSE";
			break;
		}
	}

	if (dem==n) cout<<"TRUE";
}
