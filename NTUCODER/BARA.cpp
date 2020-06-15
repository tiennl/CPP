#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k,res=0;
	cin>>n>>k;
	if (n<k){
		cout<<10;
		return 0;
	}
	n*=2;
	if (n%k==0) res=n/k;
	else res=n/k+1;
	cout<<res*5;
	return 0;
}
