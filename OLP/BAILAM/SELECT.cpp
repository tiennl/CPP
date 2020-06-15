#include <iostream>
using namespace std;
long long giaithua(int b){
	int s=1;
	for (int i=1;i<=b;i++) s=s*i;
	return s;
}
long long tohop(int mm,int k){
	int s1;
	if (k==3) s1=((mm-2)*(mm-1)*mm)/6;
	if (k==2) s1=((mm-1)*mm)/2;
	return s1;
}
main(){
	int m,n,p;
	cin>>m>>n>>p;
	if (m>2){
	    cout<<tohop(m,3);
	}
	else{
		if (m==2){
			cout<<n;
		}
	    else{
	    	if (m==1){
				if (n>1){
					cout<<tohop(n,2);
				}
		        else{
		        	if (n==1){cout<<p;}
		        }
		    }
		}
	}
}
