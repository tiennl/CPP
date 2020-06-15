#include <iostream>
using namespace std;
long long daonguoc(long long n){
	if (n>9){
		cout<<n%10;
		daonguoc(n/10);
	}
}
int main(){
	long long n;
	cin>>n;
	//	DE QUY
	cout<<daonguoc(n)<<endl;
	//	KHONG DE QUY
	while (n>0){
		cout<<n%10;
		n/=10;
	} 
	return 0;
}
