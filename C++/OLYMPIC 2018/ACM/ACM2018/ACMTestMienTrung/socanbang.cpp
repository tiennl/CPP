#include <iostream>
using namespace std;
bool kiemtra(long long x){
	int chan,le,sc,sl;
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
	long long l,r,dem,k;
	cin>>t;
	dem=0;
	for (int i=0;i<t;i++){
		for (long long i=l;i<=r;i++){
			k=i;
	 		if (kiemtra(k)==true) dem++;
	 	}
		cout<<dem<<endl;
	}
}
