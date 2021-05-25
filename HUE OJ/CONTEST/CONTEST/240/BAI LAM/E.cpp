#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#define ll long long 
ll a[10000000];
ll Count(ll a[], ll n){
	std::tr1::unordered_map<ll, ll> prev;
	ll res=0,s=0;
	for (int i=0;i<n;i++){
		s+=a[i];
		if (s==0) res++;
		if (prev.find(s)!=prev.end())
			res+=prev[s];
		prev[s]++;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	cout<<Count(a,n);
	return 0;
}
