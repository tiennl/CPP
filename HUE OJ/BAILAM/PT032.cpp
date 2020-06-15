#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll a,b,n,res=0;
	cin>>a>>b>>n;
	while (n>0){
		res++;
		n-=a;
		if (n<=0){
			cout<<res;
			return 0;
		}
		n+=b;
	}
	cout<<res;
	return 0;
}
