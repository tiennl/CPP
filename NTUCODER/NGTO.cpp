#include <bits/stdc++.h>
using namespace std;
bool isprime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	long long n;
	cin>>n;
	if (isprime(n)) cout<<"YES";
	else cout<<"NO";
	return 0;
}
