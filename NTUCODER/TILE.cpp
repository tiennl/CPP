#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100000]; 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++)
		if (a[i]>=res) res++;
	cout<<res;
	return 0;
}
