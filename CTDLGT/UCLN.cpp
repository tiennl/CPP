#include <iostream>
using namespace std;
long long ucln(long long a, long long b){
	long long r;
	while (b>0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	long long a,b;
	cin>>a>>b;
	cout<<ucln(a,b);
	return 0;
}
