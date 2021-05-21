#include <bits/stdc++.h>
using namespace std;
int x[50],a[100];
int dem=-1,d[100],res=-1;
bool isPrime(long long x){
    if (x<2) return false;
    for (int i=2;i<=sqrt(x);i++)
        if (x%i==0) return false;
    return true;
}
void nghiem(int x[],int k){
	int num=0;
	for (int i=1;i<=k;i++) cout<<a[x[i]-1]<<" ";
	cout<<endl;
}
void chinhhop(int i, int n, int k){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==k) nghiem(x,k);
			else chinhhop(i+1,n,k);
			d[j]=0;
		}
}
main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	x[0]=0;
	for (int k=n;k>=1;k--) chinhhop(1,n,k);
	cout<<res;
}

