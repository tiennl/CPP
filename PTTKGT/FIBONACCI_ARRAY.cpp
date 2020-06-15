#include <iostream>
using namespace std;
long long a[1001];
long long fibo(int n){
	a[1]=a[2]=1;
	for (int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
	return a[n];
}
int main(){
	int n;
	cin>>n;
	cout<<fibo(n);
	return 0;
}
