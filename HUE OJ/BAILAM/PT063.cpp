#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long 
#define N 1000005

int main(){
	FIO
	ll t;
	ull n,mod=1e9+7,res=0;
	cin>>t;
	while (t--){
		cin>>n;
		res=0;
		if (n%2==0){
			if (((n+1)*n+n*n*(n-1))>mod) res=((n+1)*n+n*n*(n-1))/mod;
			else res=((n+1)*n+n*n*(n-1));
			cout<<res<<endl;
		}
		else{
			if (((n*n*2+2)*(n/2)+(n*n/2+1))>mod) res=((n*n*2+2)*(n/2)+(n*n/2+1))/mod;
			else res=((n*n*2+2)*(n/2)+(n*n/2+1));
			cout<<res<<endl;
		}
	}
	return 0;
}
