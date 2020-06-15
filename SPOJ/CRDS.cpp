#include <bits/stdc++.h>
using namespace std;
#define ull long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ull t,n,mod=1e6+7;
	cin>>t;
	while (t--){
		cin>>n;
		ull res=n*(n+1)/2*3-n;
		cout<<res%mod<<endl;
	}
	return 0;
}
/*
1 : 2 = 1 triangle - 1
2 : 7 = 3 triangle - 2
3 : 15 = 6 triangle - 3
4 : 26 = 10 triangle - 4
*/
