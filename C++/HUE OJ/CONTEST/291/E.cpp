#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100

ll a[N];

int main(){
	FIO
	ll n,k,res=0;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	while (1){
		sort(a,a+n,greater<ll>());
		for (int i=0;i<k;i++){
			a[i]--;
			if (a[i]<0){
				cout<<res;
				return 0;
			}
		}
		res++;
	}
	cout<<res;
	return 0;
}
