#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll sum(ll x){
	ll r=0;
	while (x>0){
		r+=(x%10)*(x%10);
		x/=10;
	}
	return r;
}

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		ll num=i;
		while (num!=1){
			num=sum(num);
			if (num==4) break;
		} 
		if (num==1) res++;
	}
	cout<<res;
	return 0;
}
