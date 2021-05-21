#include <iostream>
#include <string>
using namespace std;
main(){
	string n;
	int k,k1,temp;
	getline(cin,n);
	temp=0;
	for (int i=n.size()-1;i>=0;i--){
	    k=(int)n[i]-48;
	    if (temp==1){
	        k--;
	        temp=0;
	    }
		if (k>=8) n[i]='8';
		else if (k>=6) n[i]='6';
		else if (k<6){
		    n[i]='8';
		    temp=1;
		}
	}
	if (temp==1) n.erase(0,1);
	cout<<n;
}
