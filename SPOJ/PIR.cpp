#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
main(){
	long double t,m,n,p,q;
	long double res;
	long double a,b,c,d,e,f;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>c>>b>>d>>a>>e>>f;
		m=a*a*d*d*(b*b+e*e+c*c+f*f-a*a-d*d);
		n=b*b*e*e*(a*a+d*d+c*c+f*f-b*b-e*e);
		p=c*c*f*f*(a*a+d*d+b*b+e*e-c*c-f*f);
		q=a*a*b*b*c*c+a*a*e*e*f*f+b*b*d*d*f*f+c*c*d*d*e*e;
		res=sqrt(m+n+p-q);
		res/=12;
		cout<<fixed<<setprecision(4);
		cout<<res<<endl;
	}
}
