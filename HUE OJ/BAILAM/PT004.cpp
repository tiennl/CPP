#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll a,b;
	cin>>a>>b;
	if (a%2!=0 && b%2!=0) cout<<"Odd";
	else cout<<"Even";
	return 0;
}
