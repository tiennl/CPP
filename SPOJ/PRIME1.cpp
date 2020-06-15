#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(long long n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,m,n;
	cin>>t; 
	while (t--){	
		cin>>m>>n;
		for (int i=m;i<=n;i++)
			if (isPrime(i)) cout<<i<<endl;
		cout<<endl; 
	}
	return 0;	
}
