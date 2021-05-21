#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	unsigned long long n,base=10e9+7,res=0;
	cin>>t;
	while (t--){
		cin>>n;
		res=0;
		if (n%2==0){
			if (((n+1)*n+n*n*(n-1))>base) res=((n+1)*n+n*n*(n-1))/base;
			else res=((n+1)*n+n*n*(n-1));
			cout<<res<<endl;
		}
		else{
			if (((n*n*2+2)*(n/2)+(n*n/2+1))>base) res=((n*n*2+2)*(n/2)+(n*n/2+1))/base;
			else res=((n*n*2+2)*(n/2)+(n*n/2+1));
			cout<<res<<endl;
		}
	}
	return 0;
}
