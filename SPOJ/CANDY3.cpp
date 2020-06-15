#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ull t,n;
	cin>>t;
	while (t--){
		cin>>n;
		ull num,sum=0;
		for (int i=0;i<n;i++){
			cin>>num;
			sum=(sum+num)%n;
		}
		if (sum) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
