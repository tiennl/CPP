#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,i,k;
	k=0;
    cin>>n;
    if (n<2){cout<<"khong nguyen to";k=1;}
    else{
    	if(n==2){cout<<"nguyen to";k=1;}
    	else{
    		if (n>2){
    		for (i=2;i<=sqrt(n);i++)
    		    if (n%i==0){
    		    	cout<<"khong nguyen to";
					k=1;
    		    	break;
				}
			}
		}
	}
	if (k==0) cout<<"nguyen to";
}
