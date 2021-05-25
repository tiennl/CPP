#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define ld long double
#define vll vector <ll>
ll C(ll n, ll k){
	ll r=1;
	for (int i=0;i<k;i++){
		r*=n-i;
		r/=i+1;
	}
	return r;
}
int main(){
	FIO
	ll n,a,b,coun=0,cc=0,r=0;
	ld res=0.0;
	cin>>n>>a>>b;
	vll v(n);
	for (int i=0;i<n;i++) cin>>v[i];
	sort(v.rbegin(),v.rend());
	for (int i=0;i<a;i++) res+=v[i];
	for (int i=0;i<n;i++){
		if (v[i]>v[a-1]) cc++;
		if (v[i]==v[a-1]) coun++;
	}
	b=min(b,coun);
	if (!cc){
		for (ll i=a;i<=b;i++)
		 	r+=C(coun,i);
	}
	else r+=C(coun,a-cc);
	res/=a;
	cout<<fixed<<setprecision(6)<<res<<endl;
	cout<<r;
	return 0;
}
