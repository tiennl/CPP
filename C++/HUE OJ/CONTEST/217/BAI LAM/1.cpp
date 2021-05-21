#include <bits/stdc++.h>
long long a[10000000],prime[100000];
using namespace std;
bool is_prime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	long long n,res=0,k=-1;
	cin>>n;
	for (int i=2;i<=10000;i++) 
		if (is_prime(i)){
			k++;
			prime[k]=i;
		}
	k++;
	for (int i=0;i<447;i++)
		for (int j=0;j<48;j++)
			for (int h=0;h<17;h++)
				if (pow(prime[i],2)+pow(prime[j],3)+pow(prime[h],4)<=n) res++;	
	cout<<res;
	return 0;
}

