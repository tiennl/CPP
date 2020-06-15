#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool prime[10000000];
void Prime(){
	ll m=1e5;
	for (int i=2;i<=m;i++) prime[i]=true;
	for (int p=2;p*p<=m;p++)  
        if (prime[p])
            for (int i=p*2;i<=m;i+=p) prime[i]=false;
}
ll reverse(ll n){
	ll r=0;
	while (n>0){
		r=r*10+n%10;
		n/=10;
	}
	return r;
}
bool isPalin(ll n){
	if (n==reverse(n)) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,res=0;
	cin>>a>>b;
	Prime();
	for (int i=a;i<=b;i++)
		if (prime[i] && isPalin(i)) res++;
	cout<<res;
	return 0;
}
