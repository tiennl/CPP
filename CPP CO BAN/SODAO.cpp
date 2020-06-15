#include <iostream>
using namespace std;
int sodao(int x){
	int s=0;
	while (x>0){
		s=s*10+(x%10);
		x/=10;
	}
	return s;
}
main(){
	int n;
	cin>>n;
	cout<<"So dao: "<<sodao(n)<<" "<<sodao(n)*2;
}
