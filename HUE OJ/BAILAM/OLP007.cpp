#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t,i,j;
	cin>>t;
	while (t--){
		cin>>i>>j;
		if (j>=i){
			if (j%2==0) cout<<(j-1)*(j-1)+i<<endl;
			else cout<<j*j-i+1<<endl;
		} 
		else{
			if (i%2==0) cout<<i*i-j+1<<endl;
			else cout<<(i-1)*(i-1)+j<<endl;
		}
	}	
	return 0;
}
