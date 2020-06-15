#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	for (int i=2;i<=sqrt(n);i++)
		while (n%i==0){
			cout<<i;
			n/=i;
			if (n>1) cout<<"*";
		}
	if (n>1) cout<<n;
	return 0;
}
