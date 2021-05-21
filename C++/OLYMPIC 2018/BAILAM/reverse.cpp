#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
main(){
	string st;
	getline(cin,st);
	int n;
	n=st.size();
	for (int i=n-1;i>=0;i--){
		cout<<st[i];
	}
}
