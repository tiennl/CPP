#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll prime[N],ans[N];

bool isPrime(ll n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
}

int main(){
	FIO
	ll n,coun=-1,k=-1,res=0;
	cin>>n;
	for (int i=2;i<=10000;i++) 
		if (isPrime(i)){
			k++;
			prime[k]=i;
		}
	k++;
	for (int i=0;i<447;i++)		
		for (int j=0;j<48;j++)	
			for (int h=0;h<17;h++)	
				if (pow(prime[i],2)+pow(prime[j],3)+pow(prime[h],4)<=n){
					coun++;
					ans[coun]=pow(prime[i],2)+pow(prime[j],3)+pow(prime[h],4);
				}
	coun++;
	sort(ans,ans+coun);
	if (coun>0) res=1;
	for (int i=1;i<coun;i++)
		if (ans[i]!=ans[i-1]) res++; 
	cout<<res;
	return 0;
}
