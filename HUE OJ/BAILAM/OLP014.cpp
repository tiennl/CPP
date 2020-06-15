#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,q,x,y;
	cin>>n>>q;
	vector <ll> a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	while (q--){
		cin>>x>>y;
		cout<<upper_bound(a.begin(),a.end(),y)-lower_bound(a.begin(),a.end(),x)<<endl;
	}
	return 0;
}
