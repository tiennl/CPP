#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod=1e9+7;
int main(){
	ll t,n,x;
	cin>>t;
	while (t--){
		cin>>n;
		x=1;
		for (int i=0;i<=n;i++){
			cout<<x<<" ";
			x=(x*(n-i)/(i+1));
		} 
		cout<<endl;
	}
	return 0;
}
