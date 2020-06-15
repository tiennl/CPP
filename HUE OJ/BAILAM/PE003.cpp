#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull unsigned long long 
#define ll long long
#define N 1000005

ull fact[10];

void factorial(){
	fact[0]=1;
	for (int i=1;i<10;i++)
		fact[i]=fact[i-1]*i;
}

ull sum(ull n){
	ull s=0;
	while (n>0){
		s+=fact[n%10];
		n/=10;
	}
	return s;
}

int main(){
	FIO
	ull n,res=0;
	cin>>n;
	factorial();
	for (int i=10;i<n;i++)
		if (sum(i)%i==0) res+=i;
	cout<<res;
	return 0;
}

