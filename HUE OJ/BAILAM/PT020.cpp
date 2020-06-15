#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool isBeautiful(ll n){
	ll r=0;
	while (n>0){
		r+=n%10;
		n/=10;
	}
	if (r%10==9) return true;
	return false;
}

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		if (isBeautiful(i)) res++;
	cout<<res;
	return 0;
}
