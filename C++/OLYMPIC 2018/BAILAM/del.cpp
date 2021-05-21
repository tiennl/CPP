#include <iostream>
#include <fstream>
using namespace std;
long long a[1000000];
long long tohop(long long m){
	long long s1=0;
	long long x=m,y=m-1;
	if (x%2==0) x/=2;
	else y/=2;
	s1=x*y;
	return s1;
}
main(){
	ifstream fi ("del.inp");
	ofstream fo ("del.out");
	long long n,chan,le;
	fi>>n;
	chan=0;
	le=0;
	for (int i=0;i<n;i++){
		fi>>a[i];
		if (a[i]%2==0) chan++;
	}
	le=n-chan;
	if (chan==n) fo<<tohop(n);
    else{
	    if (le==n)
    	  	if ((n%2)!=0) fo<<"0";
    	    else fo<<tohop(n);  	
		else
		    if ((le%2)!=0) fo<<chan*le;
		    else fo<<tohop(chan)+tohop(le);
        }
    fi.close();
    fo.close(); 
}
