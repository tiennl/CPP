#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	while (cin>>n){
		if (n==0) return 0;
		for (int i=1;i<=n;i++) a[i]=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		bool ok=0;
		for (int i=1;i<=n;i++)
			if (i!=a[a[i]]){
				ok=1;
				break;
			}
		if (ok) cout<<"not ambiguous"<<endl;
		else cout<<"ambiguous"<<endl;
	}
	return 0;
}
