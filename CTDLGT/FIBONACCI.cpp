#include <iostream>
using namespace std;
long long f[1000000];
long long fibo(long long n){
	if (n<=2) return 1;
	else return fibo(n-1)+fibo(n-2); 
}
int main(){
	long long n;
	cin>>n;	
	//	DE QUY
	cout<<fibo(n)<<endl;
	//	KHONG DE QUY
	f[1]=f[2]=1;
	for (int i=3;i<=n;i++) 
		f[i]=f[i-1]+f[i-2];
	cout<<f[n];
	
	return 0;
}
