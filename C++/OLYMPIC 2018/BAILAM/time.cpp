#include <iostream>
using namespace std;
main(){
	int h,p,s;
	cin>>h>>p>>s;
	s++;
	if (s<=59){
		cout<<h<<" "<<p<<" "<<s;
	}
	else{
		s=0;
		p++;
		if (p<=59){
			cout<<h<<" "<<p<<" "<<s;
		}
		else{
			p=0;
			h++;
			cout<<h<<" "<<p<<" "<<s;
		}
	}
}
