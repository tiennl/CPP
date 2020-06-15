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
		if (a>b) swap(a,b);
		if ((a+b)%3==0 && 2*a>=b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}



