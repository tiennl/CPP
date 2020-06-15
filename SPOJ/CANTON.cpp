#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while (t--){
		int i,n,sum=0;
		cin>>n;
		for (i=1;;i++){
			sum+=i;
			if (sum>=n) break;
		}
		int temp=n-(sum-i);
		int total=i+1;
		cout<<"TERM "<<n<<" IS ";
		if (i%2==0) cout<<temp<<"/"<<total-temp<<endl;
		else cout<<total-temp<<"/"<<temp<<endl;
	}
	return 0;
}
