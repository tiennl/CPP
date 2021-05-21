#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define N 1000005
#define maxN 1e9

int main(){
	FIO
	ll n,man=0,euc=0,che=0;
	cin>>n;
	for (ll i=0;i<n;i++){
		ll num;
		cin>>num;
		man+=abs(num);
		euc+=num*num;
		che=max(che,abs(num));
	}
	cout<<man<<endl;
	cout<<fixed<<setprecision(15)<<sqrt(euc)<<endl;
	cout<<che;
	return 0;
}
