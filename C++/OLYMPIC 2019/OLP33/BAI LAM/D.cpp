#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000][1000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i][0];
		for (int j=1;j<1+a[i][0];j++) cin>>a[i][j];
	}
	cout<<-1;
	return 0;
}
