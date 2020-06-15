#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m;
	if ((n%4096)!=0){
		m=4*(n/4096)+4;
	}
	else{
		m=4*(n/4096);
	}
	cout<<m;
	return 0;
}
