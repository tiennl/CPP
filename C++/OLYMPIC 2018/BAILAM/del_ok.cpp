#include <iostream>
using namespace std;
int a[100000];
long long giaithua(int b){
	int s=1;
	for (int i=1;i<=b;i++) s=s*i;
	return s;
}
long long tohop(int m,int k){
	int s1;
	s1=((m-1)*m)/2;
	return s1;
}
main(){
	int n,chan,le;
	cin>>n;
	chan=0;
	le=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]%2==0) chan++;
		else le++; 
	}
	if (chan==n){
		cout<<tohop(n,2);
	}
    else{
	    if (le==n){
    	  	if ((n%2)!=0) cout<<"0";
    	  	    else cout<<tohop(n,2);  	
        	}
		else{
		    if ((le%2)!=0) cout<<chan*le;
		    else cout<<tohop(chan,2)*tohop(le,2);
	 		}
        }
}
