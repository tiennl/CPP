#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,s=1;
	cin>>n;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0){
			if (i==n/i) s+=i;
			else s+=i+n/i;
		}
	if (s>n) cout<<"YES";
	else cout<<"NO";
	return 0;
}
