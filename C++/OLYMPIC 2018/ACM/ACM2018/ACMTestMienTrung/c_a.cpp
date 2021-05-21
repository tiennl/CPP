#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template<typename T>
inline std::string tostring(const T& x){
	std::ostringstream o;
	o << x;
	return o.str();
}
bool kiemtra(long long x){
	int chan,le,sc,sl;
	chan=0;
	le=0;
	sc=0;
	sl=0;
	while (x>0){
		if ((x%10)%2==0){
			chan+=x%10;
			sc++;
		}
		else{
			le+=x%10;
			sl++;
		}
		x/=10;
	}
	if (sc==sl && chan==le) return true;
	return false;
}
main(){
	int t;
	string k1;
	long long l,r,dem,k,k3,j;
	cin>>t;
	dem=0;
	for (int i=0;i<t;i++){
		cin>>l>>r;
		dem=0;
		j=l;   
		while (j<r){
			k=j;    
			k1=tostring(k);
			if (k1.size()%2!=0){
	 			j*=10;
	 		}
	 		else{
	 			if (kiemtra(k)==true) dem++;
			 }
	 		j++;
	 	}
		if (i<t-1) cout<<dem<<endl;
	}
	cout<<dem;
} 
