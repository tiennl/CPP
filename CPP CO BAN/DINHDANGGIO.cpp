#include <iostream>
using namespace std;
main(){
	int h,p;
	char ch;
	cin>>h>>ch>>p;
	if (h>=0 && h<=12){
		if (h>=0 && h<=9) cout<<"0"<<h<<":";
		if (h>=10 && h<=12) cout<<h<<":";
		if (p>=0 && p<=9) cout<<"0"<<p<<" am";
		if (p>=10 && p<=60) cout<<p<<" am";
	}
	if (h>=13 && h<=23){
		cout<<h-12<<":";
		if (p>=0 && p<=9) cout<<"0"<<p<<" pm";
		if (p>=10 && p<=60) cout<<p<<" pm";
	}
}
