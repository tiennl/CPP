#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll a,b,v,res=0;
	cin>>a>>b>>v;
	if (a>=v) cout<<1;
	else{
		res=(v-a)/(a-b)+1;
		if ((v-a)%(a-b)==0) cout<<res;
		else cout<<res+1;
	}
	return 0;
}
