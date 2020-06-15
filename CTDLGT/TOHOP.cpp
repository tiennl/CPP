#include <iostream>
using namespace std;
long long C(long long k, long long n){
	if (n==k || k==0) return 1;
	else return C(k-1,n-1)+C(k,n-1);
}
int main(){
	long long n,k;
	cin>>n>>k;
	cout<<C(k,n);
	return 0;
}
