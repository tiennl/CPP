#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,x,y;
	cin>>n;
	while (n--){
		cin>>x>>y;
		if (x==y || x-2==y){
			if (x%2==0) cout<<x+y;
			else cout<<x+2*(y/2);
		}
		else cout<<"No Number";
		cout<<endl;
	}
	return 0;	
}
