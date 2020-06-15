#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	while (cin>>n){
		if (n==0) return 0;
		cout<<n*(n+1)*(2*n+1)/6<<endl;
	}
	return 0;	
}

/* Count numbers of squares in a square
n = 1 : 1
n = 2 : 1 + 4
n = 3 : 1 + 4 + 9
n = 4 : 1 + 4 + 9 + 16
=> 1^2 + 2^2 + ... + (n-1)^2 + n^2 
= n(n+1)(2n+1)/6
*/ 

