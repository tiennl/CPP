#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long t,n,res=0,base=1000000007;
	cin>>t;
	while (t--){
		cin>>n;
		n=(n-1)/2;
		res=1+10*n*n+(16*n*n*n+26*n)/3;
		cout<<res%base<<endl;
	}
	return 0;
}

