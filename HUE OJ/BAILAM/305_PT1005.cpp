#include <bits/stdc++.h>
using namespace std;
int main(){
	float x,y,z,a,b,c;
	cin>>x>>y>>z;
	a=(3+exp(y-1))/(1+x*x*abs(y-tan(z)));
	b=1+abs(y-x)+(y-x)*(y-x)/2+(y-x)*(y-x)*(y-x)/3;
	c=x-x*x/6+x*x*x*x*x/120;
	cout<<fixed<<setprecision(4)<<a<<endl<<b<<endl<<c;
	return 0;
}
