#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,k;
	cin>>t;
	while (t--){
		cin>>n;
		while (n>0){
			k=sqrt(n);
			n-=(k*k);
			cout<<k*k<<" ";
		}
		cout<<endl;
	}
	return 0;
}
