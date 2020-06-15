#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n,f;
	cin>>t;
	while (t--){
		cin>>n>>f;
		if (f) cout<<"Pagfloyd wins."<<endl;
		else cout<<"Airborne wins."<<endl;
	}
	return 0;
}
