#include <bits/stdc++.h>
using namespace std;
unsigned long long mod(long long a,unsigned long long b, unsigned long long p){
	unsigned long long res=1;
	a%=p;
	b%=p;
	while (b>0){
		if (b%2>0) res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
int main(){
	unsigned long long n,res=1,base=1000000007;
	cin>>n;
	cout<<mod(3,n-1,base);
	return 0;
}

