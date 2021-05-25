#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll a,b,res=0;
	cin>>a>>b;
	for (int n=a;n<=b;n++){
		ll r=n-1;
		for (int i=2;i<=sqrt(n);i++)
			if (n%i==0){
				if (i==n/i) r-=i;
				else r-=(i+n/i);
			}
		if (n==1) r=1;
		res+=abs(r);
	}	
	cout<<res;
	return 0;
}

