#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 100005
ll a[N]; 
int main(){
	FIO
	ll n,res=0;
	cin>>n;
/*	for (int i=n-1;i>=0;i--) cin>>a[i];
	set <ll> s;
	for (int i=n-1;i>=0;i--){
		s.insert(a[i]);
		res+=distance(s.begin(),s.lower_bound(a[i]));
	}*/
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (a[i]<a[j]) res++;
	cout<<res;
	return 0;
}
