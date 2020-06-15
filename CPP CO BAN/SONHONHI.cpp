#include <iostream>
using namespace std;
main(){
	int a,b,c,d,min,min1,max;
	cin>>a>>b>>c>>d;
	max=a;
	if (b>max) max=b;
	if (c>max) max=c;
	if (d>max) max=d;
	min=a;
	if (b<min) min=b;
	if (c<min) min=c;
	if (d<min) min=d;
	min1=max;
	if (a<min1 && a>min) min1=a;
	if (b<min1 && b>min) min1=b;
	if (c<min1 && c>min) min1=c;
	if (d<min1 && d>min) min1=d;
	cout<<min1;
}
