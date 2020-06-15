#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
template<typename T>
inline std::string tostring(const T& x){
	std::ostringstream o;
	o << x;
	return o.str();
}
main(){
	long long n;
	long double s=1;
	float k;
	string num;
	cin>>n;
	k=(3+sqrt(6));
	for (long long i=0;i<n;i++) s*=k;
	num=tostring((unsigned long long)s); 
	int kt=0;
	
/*	for (int i=0;i<num.size();i++)
		if (num[i]=='.'){
			kt=1;
			if (i>=3) cout<<num[i-3]<<num[i-2]<<num[i-1];
			if (i==2) cout<<"0"<<num[0]<<num[1];
			if (i==1) cout<<"00"<<num[0];
		} */
	if (num.size()==1) cout<<"00"<<num[0];
	if (num.size()==2) cout<<"0"<<num[0]<<num[1];
	if (num.size()>=3) cout<<num[num.size()-3]<<num[num.size()-2]<<num[num.size()-1];
}
