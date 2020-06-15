#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool isSquare(ll n){
	ll sq=sqrt(n);
	if (sq*sq==n) return true;
	return false;
}

int main(){
	FIO
	ll n,res=1e5,num;
	cin>>n;
	while (n--){
		cin>>num;
		if (isSquare(num)) res=min(res,num);
	}
	cout<<res;
	return 0;
}
