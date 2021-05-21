#include <iostream>
#include <string>
int a[1000];
using namespace std;
main(){
	string s;
	cin>>s;
	int dem=0;
	int diem=0;
	for (int i=0;i<s.size();i++)
	    if (s[i]=='S'){
	    	dem++;	
	    	diem+=dem;
		}
		else dem=0;
	cout<<diem;
}
