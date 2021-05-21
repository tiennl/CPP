#include <bits/stdc++.h>
using namespace std;
long long tonggiaithua(long long n){
	long long res=0,so,re=1;
	while (n>0){
		so=n%10;
		re=1;
		for (int ii=1;ii<=so;ii++) re*=ii;
		res+=re;
		n/=10;
	}
	return res;
}
int main(){
	long long n,ans=0;
	cin>>n;
	for (int i=10;i<n;i++)
		if (tonggiaithua(i)%i==0) {
			ans+=i;
		}
	cout<<ans;
	return 0;
}
