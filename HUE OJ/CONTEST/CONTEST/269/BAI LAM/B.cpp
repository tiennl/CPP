#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define mod 1000000007

int main(){
	FIO
	ll n,s1,s2,s3,s4,res=0;
	cin>>n;
	s1=n;
	s2=n+1;
	s3=n+2;
	s4=n+3;
	if (s1%4==0) s1/=4;
	else if (s2%4==0) s2/=4;
	else if (s3%4==0) s3/=4;
	else s4/=4;
	res=s1%mod;
	res=(res*s2)%mod;
	res=(res*s3)%mod;
	res=(res*s4)%mod;
	cout<<res;
	return 0;
}
