#include <iostream>
using namespace std;
main(){
	long long n,m,s;
	cin>>n>>m;
	s=0;
	for (long long i=1;i<=n;i++){
		s=(s+(i*i)%m)%m;
	}
	cout<<s;
}
