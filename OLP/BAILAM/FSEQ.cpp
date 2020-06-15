#include <iostream>
using namespace std;
int a[30000];
int kt[30000];
main(){
	int n,max,dem;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if ((i>=2) && (a[i]==a[i-1]+a[i-2])) kt[i]=1;
		else kt[i]=0;
	}
	max=0;
	for (int i=0; i<=n-1;i++){
		if (kt[i]==1){
			dem=1;
			if (dem>max) max=dem;
	    	for (int j=i+1;j<=n;j++){
	        	if (kt[j]==1){
	        		++dem;
	        		if (dem>max) max=dem;
				}
				else{
					dem=0;
					break;
        		}
			}    	
		}
	}
    if (max==0) cout<<"-1";
	else cout<<max+2;
}
