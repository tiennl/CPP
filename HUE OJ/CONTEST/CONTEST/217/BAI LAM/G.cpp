#include <bits/stdc++.h>
long long prime[1000000],ans[1000000];
using namespace std;
bool is_prime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	long long n,coun=-1,k=-1,res=0;
	cin>>n;
	for (int i=2;i<=10000;i++) 
		if (is_prime(i)){
			k++;
			prime[k]=i;
		}
	k++;
	for (int i=0;i<447;i++)			//vi tri cua so nguyen to >= can bac 2 cua 10^7
		for (int j=0;j<48;j++)		//vi tri cua so nguyen to >= can bac 3 cua 10^7
			for (int h=0;h<17;h++)	//vi tri cua so nguyen to >= can bac 4 cua 10^7
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
