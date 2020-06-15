#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005
map <ll,ll> a;
int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=0;i<n;i++){
		ll num;
		cin>>num;
		a[num]=1;
	}
	for (int i=0;i<=N;i++){
		if (a[i*i]==0){
			cout<<i*i;
			return 0;
		}
	}
	return 0;
}
