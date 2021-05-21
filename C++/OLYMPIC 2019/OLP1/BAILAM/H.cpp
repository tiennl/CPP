#include <bits/stdc++.h>
using namespace std;
int bcnn(int a, int b){
	return a*b/__gcd(a,b);
}
int main(){
	int n,res=0;
	cin>>n;
	if (n==1){
		cout<<1;
		return 0;
	}
	res=n;
	for (int i=1;i<=n/2+1;i++)
		if (bcnn(i,n-i)>res){
			res=bcnn(i,n-i);
	//		cout<<i<<" "<<n-i<<endl;
		}
	cout<<res;
	return 0;
}
