#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool isPrime(ll n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
}

int main(){
	FIO
	ll n;
	cin>>n;
	if (n==2){
		cout<<3;
		return 0;
	}
	if (isPrime(n)) n++;
	while (!isPrime(n)) n++;
	cout<<n;
	return 0;
}