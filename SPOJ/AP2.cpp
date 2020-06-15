#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	while (t--){
		ll t3,t3last,sum,n,ap,first;
		cin>>t3>>t3last>>sum;
		n=sum*2/(t3+t3last);
		ap=(t3last-t3)/(n-5);
		first=t3-2*ap;
		cout<<(ll)n<<endl;
		for (int i=0;i<(ll)n;i++){
			cout<<first<<" ";
			first+=ap;
		}
		cout<<endl;
	}
	return 0;
}
