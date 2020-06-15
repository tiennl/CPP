#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	while (t--){
		ll n,x,y;
		cin>>n>>x>>y;
		for (int i=2;i<n;i++)
			if (i%x==0 && i%y!=0) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
