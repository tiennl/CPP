#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define PI 3.1416
main(){
	float a,b,angle,s;
	cin>>a>>b>>angle;
	s=a*b*sin(angle*PI/180)/2;
	cout<<fixed<<setprecision(2);
	cout<<s;
}
