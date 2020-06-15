#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	for (int i=1;i<=t;i++){
		double r,s;
		cin>>r;
		s=0.25+4*r*r;
		cout<<"Case "<<i<<": ";
		cout<<fixed<<setprecision(2)<<s<<endl;
	}
	return 0;
}
