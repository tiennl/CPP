#include <iostream>
using namespace std;
int a[1000000];
main(){
	int n,max,dem;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	max=0;
	for (int i=0; i<=n-1;i++){
		dem=1;
	    for (int j=i+1;j<=n;j++){
	        if (a[j-1]<=a[j]){
	        	++dem;
	        	if (dem>max) max=dem;
			}
			else break;
        }
    }
        cout<<max;
}

