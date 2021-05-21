#include <iostream>
#include <string>
using namespace std;
main(){
	int n,am=0,duong=0;
	cin>>n;
	string s;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s[0]=='-') am++;
		else if (s[0]!='0' && s[0]!='-') duong++;
	}
	cout<<am<<" "<<duong;
}
