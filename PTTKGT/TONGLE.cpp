#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	while (n>0){
		if ((n%10)%2!=0) res+=n%10;
		n/=10;
	}
	cout<<res;
	return 0;
}
