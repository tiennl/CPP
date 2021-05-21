#include <bits/stdc++.h>
long long f[10000000],x[10000000];
long long res=0;
using namespace std;
void back(long long i, long long f[], long long x[], long long &n, long long &count, long long &res){
	int k,j=n;
	while (f[j]>i) j--;
	for (int j=j;j>=2;j--)
		if (f[j]<f[x[count]]){
			count++;
			x[count]=j;
			k=i-f[j];
			if (k==0) res++;
			else back(k,f,x,n,count,res);
			count--;
		}
}
int main(){
	long long t,m,i,n=0,count=0;
	cin>>t;
	while (t--){
		cin>>m;
		if (m>=1) i=1,f[i]=1;
		if (m>=2) i=2,f[i]=2;
		while (f[i]+f[i-1]<=m){
			i++;
			f[i]=f[i-1]+f[i-2];
		} 
		n=i;
		count=0;
		x[0]=0;
		res=0;
		back(m,f,x,n,count,res);
		cout<<res<<endl;
	}
	return 0;
}
