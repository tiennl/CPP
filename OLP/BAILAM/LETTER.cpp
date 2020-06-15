#include <iostream>
#include <string>
using namespace std;
main(){
	string st;
	int k;
	getline(cin,st);
	cin>>k;
	int n;
	n=st.size();
	for (int i=k-1; i>=0; i--)
	    cout<<st[i];
	for (int i=n-1; i>=k; i--) 
	    cout<<st[i];
}
