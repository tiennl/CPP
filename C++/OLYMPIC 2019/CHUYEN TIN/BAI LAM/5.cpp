#include <bits/stdc++.h>
using namespace std;
int main(){
	double d1,d2;
	for (double a=0;a<20;a+=0.01)
	for (double b=0;b<20;b+=0.01)
	for (double c=0;c<20;c+=0.01)
	for (double d=0;d<20;d+=0.01)
		if (a+b+c+d==a*b*c*d && a+b+c+d<=20)		
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	
	return 0;
}
