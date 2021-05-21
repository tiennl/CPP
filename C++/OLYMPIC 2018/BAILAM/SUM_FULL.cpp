#include <fstream>
using namespace std;
ifstream doc("SUM.INP");
ofstream ghi("SUM.OUT");
double a,b;
main(){
	doc>>a>>b;
	long long x=a,y=b;
	if(x==a) x--;
	long long x1,x2,x3,y1,y2,y3,l,r;
	x1=2*x+1; x2=x+1; x3=x;
	y1=2*y+1; y2=y+1; y3=y;
	if(x3%2==0) x3=x3/2;
	else x2=x2/2;
	if(x3%3==0) x3=x3/3;
	else{
		if(x2%3==0) x2=x2/3;
		else x1=x1/3;
	}
	l=(x2*x3)%1000000007;
	l=(l*x1)%1000000007;
	
	if(y3%2==0) y3=y3/2;
	else y2=y2/2;
	if(y3%3==0) y3=y3/3;
	else{
		if(y2%3==0) y2=y2/3;
		else y1=y1/3;
	}
	r=(y2*y3)%1000000007;
	r=(r*y1)%1000000007;
	
	if(r-l>=0) ghi<<r-l;
	else ghi<<r-l+1000000007;
}
