#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define pb push_back 
#define N 1000005

ll maxDigit(ll n){
	ll r=0;
	while (n>0){
		r=max(r,n%10);
		n/=10;
	}
	return r;
}

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	while (n>0){
		res++;
		n-=maxDigit(n);
	}
	cout<<res;
	return 0;
}
