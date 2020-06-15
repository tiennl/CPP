#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,res;
	cin>>n;
	if (n==-1 || n==0) cout<<1;
	else if (n%2==0){
		res=2;
		for (int i=4;i<=n;i+=2) res*=i;
		cout<<res;
	}
	else{
		res=1;
		for (int i=3;i<=n;i+=2) res*=i;
		cout<<res;
	}
	return 0;
}
