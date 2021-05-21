#include <bits/stdc++.h>
int n=3;
int x[50];
int d[100];
long long res=-1;
using namespace std;
bool isPrime(long long x){
    if (x<2) return false;
    for (int i=2;i<=sqrt(x);i++)
        if (x%i==0) return false;
    return true;
}
void nghiem(int x[],int k, int digits[]){
    long long num=0;
	for (int i=1;i<=k;i++) num=num*10+digits[x[i]-1];
    if (isPrime(num)) res=max(res,num); 
}
void chinhhop(int i, int n, int k, int digits[]){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==k) nghiem(x,k,digits);
			else chinhhop(i+1,n,k,digits);
			d[j]=0;
		}
}
int findTheLargestPrime(int digits[])
{
    x[0]=0;
	for (int k=1;k<=n;k++)
        chinhhop(1,n,k,digits);
}
int main(){
	int digits[]={2,4,7};
	cout<<findTheLargestPrime(digits);
}
