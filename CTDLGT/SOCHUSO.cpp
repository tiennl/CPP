#include <iostream>
using namespace std;
long long sochuso(long long n){
	if (n<10) return 1;
	else return sochuso(n/10)+1;
}
int main(){
	long long n,res=0;
	cin>>n;	
	//	DE QUY
	cout<<sochuso(n)<<endl;
	//	KHONG DE QUY
	while (n>0){
		res++;
		n/=10;
	}
	cout<<res;
	return 0;
}
