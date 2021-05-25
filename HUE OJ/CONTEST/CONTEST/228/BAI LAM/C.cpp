#include <bits/stdc++.h>
using namespace std;
long long poww(long long a,long long b,long long p){
	long long ret = 1;
    a%=p;
    b%=p-1;
    while (b>0){
        if (b%2>0)  
            ret=ret*a%p;
        a=a*a%p;  
        b/=2;
    }
    return ret;
}
int main(){
	unsigned long long n,m,res1=1,res2=1,mod=1000000007;
	cin>>n;
	if (n==0){
		cout<<1;
		return 0;
	}
	res1=poww(2,2*n-1,mod);
	res2=poww(2,n-1,mod);
	if (res1+res2>mod) cout<<(res1+res2)%mod;
	else cout<<res1+res2;
	return 0;
}
