#include <bits/stdc++.h>
using namespace std;
long long sum(long long n){
	long long ans=0;
	while (n>0){
		ans+=(n%10);
		n/=10;
	}
	return ans;
}
int main(){
	long long n;
	cin>>n;
	if (n%sum(n)==0) cout<<1;
	else cout<<0;
	return 0;
}
