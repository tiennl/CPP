#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005

bool prime[N];

void sieve(){
	for (int i=2;i<=N;i++) prime[i]=true;
	for (int p=2;p*p<=N;p++)
		if (prime[p])
			for (int i=p*2;i<=N;i+=p) prime[i]=false;
}

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	sieve();
	for (int i=2;i<=sqrt(n);i++)
		if (prime[i] && i*i<=n) res++;
	cout<<res;
	return 0;
}
