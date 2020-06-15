#include <iostream>
using namespace std;
long long pow(int x, int n){
	long long p=1;
	while (n>0){
		while (n%2==0){
			x*=x;
			n/=2;
		}
		p*=x;
		n--;
	}
	return p;
}
int main(){
	int x,n;
	cin>>x>>n;
	cout<<pow(x,n);
	return 0;
}
