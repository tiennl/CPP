#include <iostream>
using namespace std;
int digit(int n){
	int r=0;
	while (n>0){
		r++;
		n/=10;
	}
	return r;
}
int main(){
	int n;
	cin>>n;
	cout<<digit(n);
	return 0;
}
