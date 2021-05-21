#include <iostream>
using namespace std;
main(){
	int m,n;
	cin>>m>>n;
	int ga,tho;
	tho=(n-2*m)/2;
	ga=m-tho;
	int kq;
	kq=0;
	if ((ga>=0) && (tho>=0)){
	    cout<<ga<<" "<<tho;
	    kq=1;
    }     
	else{
		cout<<"-1";
	}
}
