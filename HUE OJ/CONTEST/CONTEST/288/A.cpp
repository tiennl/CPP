#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool isPrime(int n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n+2);i++)
		if (n%i==0 || (n+2)%i==0) return false;
	return true;
}

int main(){
	FIO
	ll n,m,res=0;
	cin>>n>>m;
	for (int i=n;i<=m-2;i++)
		if (isPrime(i)) res++;
	cout<<res;
	return 0;
}
