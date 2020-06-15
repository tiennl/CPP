#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll t,n;
	cin>>t;
	while (t--){
		cin>>n;
		if (n%2!=0) cout<<(n*(n+2)*(2*n+1)-1)/8<<endl;
		else cout<<(n*(n+2)*(2*n+1))/8<<endl;
	}
	return 0;
}
