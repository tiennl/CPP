#include <iostream>
using namespace std;
long long a[50][50];
int main(){
	long long t,n0,n,d;
	cin>>t;
	while (t--){
		cin>>n0>>n>>d;
		cout<<n*(2*n0+(n-1)*d)/2<<endl;
	}
	return 0;
}
