#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll q;
	cin>>q;
	while (q--){
		ll x,res=0;
		cin>>x;
		x=abs(x);
		while (x>0){
			res++;
			x-=res;
		}
		if (x%2==0) cout<<res<<endl;
		else cout<<res+1+res%2<<endl;
	}
	return 0;
}
