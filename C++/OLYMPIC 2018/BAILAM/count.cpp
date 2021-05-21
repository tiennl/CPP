#include <iostream>
#include <string>
using namespace std;
main(){
	string s,s1;
	cin>>s>>s1;
	int dem;
	dem=0;
	int pos;
	while (s.find(s1) != (-1)){
	    pos=s.find(s1);
		s.erase(pos,s1.size());
		dem++;
	}
	cout<<dem;
}
