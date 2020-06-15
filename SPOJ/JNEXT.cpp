#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll t,n;
	cin>>t;
	while (t--){
		cin>>n;
		ll a[n];
		for (int i=0;i<n;i++) cin>>a[i];
		if (next_permutation(a,a+n))
			for (int i=0;i<n;i++) cout<<a[i];
		else cout<<-1;
		cout<<endl;
	}
	return 0;
}
