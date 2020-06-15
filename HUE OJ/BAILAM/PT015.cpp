#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t,n;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=i;j++) cout<<"* ";
			cout<<endl;
		}
		for (int i=n-1;i>=1;i--){
			for (int j=1;j<=i;j++) cout<<"* ";
			cout<<endl;
		}
	}
	return 0;
}
