#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,m,n,c,d;
	cin>>t;
	while (t--){
		cin>>m>>n>>c>>d;
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++)
				if (i==c || j==d) cout<<"*";
				else cout<<".";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
