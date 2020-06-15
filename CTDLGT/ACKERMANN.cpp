#include <iostream>
using namespace std;
long long A(long long m, long long n){
	if (m==0) return n+1;
	else if (n==0) return A(m-1,1);
	else if (m>0 || n>0) return A(m-1,A(m,n-1));
	return 0;
}
int main(){
	long long m,n;
	cin>>m>>n;
	cout<<A(1,2)<<endl;
	cout<<A(m,n);
	return 0;
}
