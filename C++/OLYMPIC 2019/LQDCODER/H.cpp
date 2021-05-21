#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 1000000 
const ll mod=998244353;
ll fa[N],fi[N],in[N];
ll solve(ll n, ll k){
	if (n<k) return 0;
	if (n<0 || k<0) return 0;
	return fa[n]*(fi[k]*fi[n-k]%mod)%mod;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,a,b,k,res=0;
	cin>>n>>a>>b>>k;
	fa[0]=1;
	fa[1]=1;
	fi[0]=1;
	fi[1]=1;
	in[1]=1;
	for (int i=2;i<N;i++){
		fa[i]=fa[i-1]*i%mod;
		in[i]=mod-in[mod%i]*(mod/i)%mod;
		fi[i]=fi[i-1]*in[i]%mod;
	}
	for (int i=0;i<n+1;i++){
		if ((k-a*i)%b==0){
			ll j=(k-a*i)/b;
			if (j>=0 && j<=n){
				res+=solve(n,i)*solve(n,j);
				res%=mod;
			}
		}
	}
	cout<<res;
	return 0;
}
