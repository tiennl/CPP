#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll a[100000];
int main(){
	FIO
	ll n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++)
			if (a[j]>=m-i) cout<<"#";
			else cout<<".";
		cout<<endl;
	}
	return 0;
}
