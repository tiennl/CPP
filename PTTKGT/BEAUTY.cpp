#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isPrime(ll n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
}

ll sumDigits(ll n){
	ll r=0;
	while (n>0){
		r+=(n%10)*(n%10);
		n/=10;
	}
	return r;
}

int main(){
	ll n,i=0,num=0;
	cin>>n;
	while (i<n){
		num++;
		if (isPrime(sumDigits(num))) i++;
		if (i==n){
			cout<<num;
			return 0;
		}
	}
	return 0;
}
