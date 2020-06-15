#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	for (int j=1;j<=t;j++){
		ll sum,n,s=0;
		cin>>sum>>n;
		for (int i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
		}
		cout<<"Scenario #"<<j<<":"<<endl;
		if (s<sum) cout<<"impossible"<<endl;
		else{
			ll res=0,sr=0;
			sort(a,a+n,greater<ll>());
			for (int i=0;i<=n;i++){
				if (sr>=sum){
					cout<<res<<endl;
					break;
				}
				sr+=a[i];
				res++;
			}
		}
		cout<<endl;
	}
	return 0;
}
