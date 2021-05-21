#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll a,b,c,d,res=0;
	cin>>a>>b>>c>>d;
	for (int i=a;i<=b;i++)
		for (int j=c;j<=d;j++)
			if (__gcd(i,j)==1) res++;
	cout<<res;
	return 0;
}
