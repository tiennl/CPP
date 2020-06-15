#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k=0;
	cin>>n;
	while (n>0){
		k++;
		n-=k;
	}
	if (n==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
