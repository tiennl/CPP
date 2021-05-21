#include <bits/stdc++.h>
typedef unsigned long long ull;
ull a[10000000],p[10000000];
bool is_p[10000000];
using namespace std;
ull poww(ull x, ull y, ull mod){
	ull ret=1;
    x%=mod;
    y%=mod-1;
    while (y>0){
        if (y%2>0)  
            ret*=x%mod;
        x*=x%mod;  
        y/=2;
    }
    return ret;
}
void tu(ull a[], ull n, ull m){
	m++;
	for (int i=0;p[i]*p[i]<=n && i<m;i++){
		if (n%p[i]==0){
			a[p[i]]++;
			n/=p[i--];
		}
	}
	if (n!=1) a[n]++;
}
void mau(ull a[], ull n, ull m){
	m++;
	for (int i=0;p[i]*p[i]<=n && i<m;i++){
		if (n%p[i]==0){
			a[p[i]]--;
			n/=p[i--];
		}
	}
	if (n!=1) a[n]--;
}
int main(){
	ull t,n,m,k,num,j,x1,x2,res=0,mod=1000003;
	cin>>t;
	for (int ii=1;ii<=t;ii++){
		cin>>n>>k;
		cout<<"Case "<<ii<<": ";
		m=-1;
		for (int i=0;i<=n;i++) is_p[i]=true;
		for (int i=2;i<n;i++){
        	if (is_p[i]){
        		m++;
        		p[m]=i;
			}
    		for (int j=0;j<m+1;i++){
				if (i*p[j]<n) is_p[i*p[j]]=false;
				if (i%p[j]==0) break;
        	}
		}
        for (int i=2;i<=n;i++) a[i]=0;
        x1=k;
        x2=n-k;
        if (x1<x2) swap(x1,x2);
        for (int i=x1+1;i<=n;i++){
        	num=i;
        	j=2;
        	tu(a,num,m);
		}        
		for (int i=2;i<=x2;i++){
        	num=i;
        	j=2;
        	mau(a,num,m);
		}         	
		res=1;
        for (int i=2;i<=n;i++){
        	if (a[i]>0) res*=poww(i,a[i],mod),a[i]=0;
        	if (res>mod) res%=mod;
        	if (a[i]<0 && res%poww(i,abs(a[i]),mod)==0) res/=poww(i,abs(a[i]),mod),a[i]=0;
        }
        for (int i=2;i<=n;i++){
        	if (a[i]<0) res/=poww(i,abs(a[i]),mod),a[i]=0;
        }
        if (res>mod) cout<<res%mod;
        else cout<<res;
        cout<<endl;
	}
	return 0;
}
