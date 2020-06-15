#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10000005

ll a[N];

bool isPrime(ll x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}

ll divisorMin(long long x){
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return i;
	return 0;
}

bool check(ll x){
	ll multi=1,y=x;
	while (x>0){
		multi*=(x%10);
		x/=10;
	}
	if (multi==y) return true;
	else return false;
}

int main(){
	FIO
	ll n,k=-1,num=0;
	cin>>n;
	if (n==0) cout<<10;
	else if (n>=1 && n<=9) cout<<n;
	else if (!isPrime(n) && divisorMin(n)>9) cout<<-1;
	else if (isPrime(n)){
		if (check(n)) cout<<n;
		else cout<<-1;
		return 0;
	}
	else{
		num=9;
		k=-1;
		while (n>1){
			if (n%num==0){
				k++;
				a[k]=num;
				n/=num;
				if (!isPrime(n) && divisorMin(n)>9){
					cout<<-1;
					return 0;
				}
				else if (isPrime(n) && n>9){
					if (check(n)){
						k++;
						a[k]=n;
					}
				    else cout<<-1;
					return 0;
				}
			}
			else num--;
		}
		for (int i=k;i>=0;i--) cout<<a[i];
	}
	return 0;
}
