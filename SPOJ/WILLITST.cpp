#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	if ((n & (n-1))==0) cout<<"TAK";
	else cout<<"NIE";
	return 0;
}
