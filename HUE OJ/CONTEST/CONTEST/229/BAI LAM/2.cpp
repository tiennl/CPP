#include <bits/stdc++.h>
long long a[1000000];
bool prime[1000000];
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
	long long t,n,k,num,j,res=0,mod=1000003;
	cin>>t;
	for (int ii=1;ii<=t;ii++){
		cin>>n>>k;
		cout<<"Case "<<ii<<": ";
		for (int i=0;i<=n;i++) prime[i]=true;
		for (int p=2;p*p<=n;p++)  
        	if (prime[p])
            	for (int i=p*2;i<=n;i+=p) 
                	prime[i]=false; 
        for (int i=2;i<=n;i++) a[i]=0;
        for (int i=2;i<=n;i++){
        	num=i;
        	j=2;
        	while (num>1){
        		while (num%j==0 && prime[j]) a[j]++,num/=j;
				j++; 
			}
		}        
		for (int i=2;i<=k;i++){
        	num=i;
        	j=2;
        	while (num>1){
        		while (num%j==0 && prime[j]) a[j]--,num/=j;
				j++; 
			}
		}     
		for (int i=2;i<=n-k;i++){
        	num=i;
        	j=2;
        	while (num>1){
        		while (num%j==0 && prime[j]) a[j]--,num/=j;
				j++; 
			}
		}           	
	/*	res=0;
        for (int i=2;i<=n;i++){
        	if (a[i]>0) res*=poww(i,a[i],mod),a[i]=0;
        	if (res>mod) res%=mod;
        	if (a[i]<0 && res%pow(i,a[i],mod)==0) res/=pow(i,a[i],mod),a[i]=0;
        }
        for (int i=2;i<=n;i++){
        	if (a[i]<0) res/=pow(i,a[i],mod),a[i]=0;
        }
        if (res>mod) cout<<res%mod;
        else cout<<res;*/
	}
	return 0;
}
