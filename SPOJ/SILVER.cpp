#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n;
	while (cin>>n){
		if (n==0) return 0;
		ll res=0;
		while (n>1){
			n/=2;
			res++;
		}
		cout<<res<<endl;
	}	
	return 0;
}
