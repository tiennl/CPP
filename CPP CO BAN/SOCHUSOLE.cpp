#include <iostream>
using namespace std;
int sole(int x){
	int d=0;
	while (x>0){
		if ((x%10)%2!=0) d++;
		x/=10;
	}
	return d;
}
main(){
	int n;
	cin>>n;
	cout<<sole(n);
}
