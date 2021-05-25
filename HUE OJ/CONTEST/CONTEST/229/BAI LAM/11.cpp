#include <bits/stdc++.h>
using namespace std;
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
long long C(long long n, long long k, long long mod){
	long long c=1;
	if (n==k) return 1;
	k=min(k,n-k);
   	for (int i=1;i<=k;i++,n--){
   		tu(a,n,m);
   		mau(a,i,m);
   	}
  	return c;
}
int main(){
	long long t,n,k,mod=1000003;
	cin>>t;
	m=-1;
		n=1000000;
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
	for (int i=1;i<=t;i++){
		cin>>n>>k;
		cout<<"Case "<<i<<": "<<C(n,k,mod)<<endl;
	}
	return 0;
}
