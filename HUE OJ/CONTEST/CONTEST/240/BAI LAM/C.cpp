#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,p,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>p;
		res+=pow(p/10,p%10);
	}
	cout<<res;
	return 0;
}
