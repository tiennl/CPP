#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main(){
	ll t;
	cin>>t;
	while (t--){
		ull k,res=1e12,v1=0,v2=0,n=0;
		cin>>k;
		for (ll m=1;m<=sqrt(k);m++){
			n=(2*k-m-1)/(2*m+1);
			if ((n*m+(n+1)*(m+1)==2*k) && (m<=n) && (n-m<res)){
					res=n-m;
					v1=m;
					v2=n;
			}
		}
		if (v1!=0 && v2!=0) cout<<v1<<" "<<v2<<endl;
		else cout<<"-1 -1"<<endl;
	}
	return 0;
}
