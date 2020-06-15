#include <iostream>

using namespace std;

int f[1000];

int fibo(int n){
	if (n==1 || n==2) return 1;
	return fibo(n-1)+fibo(n-2);
}

int main(){
	int n;
	cin>>n;
	cout<<fibo(n)<<endl;
	f[1]=1;
	f[2]=1;
	for (int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	cout<<f[n];
	return 0;
}
