#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 

bool isPrime(ll n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
} 

bool isPalin(ll n){
	ll r=0,m=n;
	while (n>0){
		r=r*10+n%10;
		n/=10;
	}
	if (r==m) return true;
	return false;
}

int main(){
	FIO
	ll a,b,res=0;
	cin>>a>>b;
	for (int i=a;i<=b;i++)
		if (isPrime(i) && isPalin(i)) res++;
	cout<<res;
	return 0;
}
