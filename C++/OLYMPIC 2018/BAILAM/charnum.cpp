#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
main(){
	string st;
	int d;
	d=0;
	getline(cin,st);
	for (int i=0 ; i<st.size() ; i++)
	    if (st[i]>='0' && st[i]<='9'){
	    	++d;
		}
	cout<<d;
}
