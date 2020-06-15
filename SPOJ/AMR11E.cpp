#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1005
ll a[N];
bool fac(ll n){
	ll coun=0,ok=1;
	while (n%2==0){
		if (ok) coun++,ok=0;
		n/=2;
	}
	for (int i=3;i<=sqrt(n);i++){
		ok=1;
		while (n%i==0){
			if (ok) coun++,ok=0;
			n/=i;
		}
	}
	if (n>2) coun++;
	if (coun>=3) return true;
	return false;
}
int main(){
	FIO
	ll t,n,num=29,m=0;
	cin>>t;
	while (m<1000){
		num++;
		if (fac(num)){
			m++;
			a[m]=num;
		}
	}
	while (t--){
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
