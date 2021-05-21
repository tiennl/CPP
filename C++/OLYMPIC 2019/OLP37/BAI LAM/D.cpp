#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,q;
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>a[i];
	while (q--){
		int l,r,res=0;
		cin>>l>>r;
		for (int i=l;i<=r;i++){
			set <ll> s;
			for (int j=i;j<=r;j++){
				s.insert(a[j]);
				if (s.size()==j-i+1) res=max(res,j-i+1);
				else break;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
