#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,res=0;
	cin>>n;
	res=n;
	if (n<10){
			cout<<n;
			return 0;
		}
	while (n>9){
		res+=(n/10)*3;
		n=n%10+(n/10)*3;
	}
	cout<<res;
	return 0;
}
