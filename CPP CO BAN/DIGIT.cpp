#include <iostream>
using namespace std;
int digit(long long n,int k){
	int sl=0;
	while (n>0){
		sl++;
		if (sl==k) return n%10;
		n/=10;
	}
	return 0;
}
int main(){
	long long n;
	int k;
	cin>>n>>k;
	cout<<digit(n,k);
	return 0;
}
