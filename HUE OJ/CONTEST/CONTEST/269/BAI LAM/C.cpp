#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define mod 1000000007

ll sum(ll s){
	ll ss,s1,s2,s3;
	s1=2*s+1; 
	s2=s+1; 
	s3=s;
	if (s3%2==0) s3/=2; 
	else s2/=2;
	if (s3%3==0) s3/=3;
	else{
		if (s2%3==0) s2/=3;
		else s1/=3;
	}
	ss=(s2*s3)%mod;
	ss=(ss*s1)%mod;
	return ss;
}

int main(){
	FIO
	double a,b;
    ll t1,t2;
    cin>>a>>b;
    ll n=a,m=b;
	if(n==a) n--;
    t1=sum(n);
    t2=sum(m);
    if (t2-t1>=0) cout<<t2-t1;
	else cout<<t2-t1+mod;
	return 0;
}
