#include <bits/stdc++.h>
long long a[1000];
using namespace std;
bool is_prime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	long long t,n,k,m,num,temp=1;
	unsigned long long res=0;
	cin>>t;
	while (t--){
		cin>>n>>k;
		temp=1;
		res=1;
		m=max(max(n+k-1,k),n-1);
		for (int i=1;i<=m;i++) a[i]=0;
		for (int i=2;i<=n+k-1;i++){
			num=i;
			temp=2;
			while (num>1){
				if (num%temp==0 && is_prime(temp)) a[temp]++,num/=temp;
				else temp++;
			}
		}
		for (int i=2;i<=k;i++){
			num=i;
			temp=2;
			while (num>1){
				if (num%temp==0 && is_prime(temp)) a[temp]--,num/=temp;
				else temp++;
			}
		}
		for (int i=2;i<=n-1;i++){
			num=i;
			temp=2;
			while (num>1){
				if (num%temp==0 && is_prime(temp)) a[temp]--,num/=temp;
				else temp++;
			}
		}
		for (int i=2;i<=m;i++)
			if (a[i]>0) res*=pow(i,a[i]);
			else if (a[i]<0) res/=pow(i,a[i]);
		cout<<res<<endl;	 
	}
	return 0;
}
