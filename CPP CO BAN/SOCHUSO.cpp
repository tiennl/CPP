#include <iostream>
using namespace std;
int scs(int x){
	int s=0;
	while (x>0){
		s++;
		x/=10;
	}
	return s;
}
main(){
	int n;
	cin>>n;
	cout<<"So chu so: "<<scs(n);
}
