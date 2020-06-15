#include <bits/stdc++.h>
using namespace std;
int main(){
	long long h,p,s;
	cin>>h>>p>>s;
	s++;
	if (s>=60){
		s-=60;
		p++;
		if (p>=60){
			h++;
			p-=60;
			if (h>=24) h-=24;
		}	
	}
	cout<<h<<" "<<p<<" "<<s;
	return 0;
}
