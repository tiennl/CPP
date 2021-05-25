#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll k,s,res=0;
	cin>>k>>s;
	for (int i=0;i<=k;i++)
		for (int j=0;j<=k;j++)
			if (s-i-j>=0 && s-i-j<=k) res++;
	cout<<res;
	return 0;
}
