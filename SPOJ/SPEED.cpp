#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t,a,b;
	cin>>t;
	while (t--){
		cin>>a>>b;
		cout<<abs(a-b)/abs(__gcd(a,b))<<endl;
	}	
	return 0;
}
