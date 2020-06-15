#include <iostream>
using namespace std;
main(){
	int a,b,chan,le,s,so,dem;
	cin>>a>>b;
	chan=0;
	le=0;
	dem=0;
	for (int i=a; i<=b; i++){
    	s=i;
    	chan=0;
		le=0;
		while (s!=0){
			so=s%10;
			if (so%2==0){
				chan=chan+so;
			}
			else{
				le=le+so;
			}
			s=s/10;
		}
		if (chan==le){
			++dem;
		}
    }
 	cout<<dem;
}
