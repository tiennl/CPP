#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,res=0;
	cin>>n;
	m=n;
	for (int i=1;i<=sqrt(n);i++){
		if (n%i==0)
			if (n/i==i) res+=i;
			else res+=(n/i+i);
	}
	res-=m;
	if (res==m) cout<<"YES";
	else cout<<"NO";
	return 0;
}
