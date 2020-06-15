#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,sum=0;
	cin>>n;
	while (n>0){
		sum+=(n%10);
		n/=10;
	}
	if (sum%10==9) cout<<"YES";
	else cout<<"NO";
	return 0;
}
