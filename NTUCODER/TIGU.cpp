#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,res=0;
	cin>>n>>m;
	while (n<m){
		res++;
		n+=round(n/10.0);
	}
	cout<<res;
	return 0;
}
