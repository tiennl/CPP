#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
main(){
	string st;
	getline(cin,st);
	for (int i=0 ; i<st.size() ; i++)
	    if (st[i]>='0' && st[i]<='9'){
	    	st.erase(i,1);
	    	i--;
		}
	cout<<st;
}
