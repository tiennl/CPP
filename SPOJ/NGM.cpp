#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	if (n%10==0) cout<<2;
	else cout<<1<<endl<<n%10;
	return 0;
}
