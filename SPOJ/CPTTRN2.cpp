#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++)
				if (i==0 || i==n-1 || j==0 || j==m-1) cout<<"*";
				else cout<<".";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
