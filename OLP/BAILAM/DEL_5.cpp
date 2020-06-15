#include <iostream>
using namespace std;
main(){
	int a[100000];
	int n,dem,tong;
	cin>>n;
	tong=0;
	for (int i=0;i<n;i++){
	    cin>>a[i];
	    tong=tong+a[i];
    }
    cout<<tong<<endl;
    dem=0;
	for (int i=0;i<n-1;i++)
	    for (int j=i+1;j<n;j++)
	        if ((tong-a[i]-a[j])%2==0){
	        	++dem;
			}
	cout<<dem;
}
