#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull long long 

int main(){
	FIO
	ull n,m,s=0;
	cin>>n;
	m=n;
	while (n>0){
		s+=n%10;
		n/=10;
	}
	if (m%s==0) cout<<1;
	else cout<<0;
	return 0;
}
