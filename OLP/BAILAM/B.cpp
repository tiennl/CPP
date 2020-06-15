#include <iostream>
using namespace std;
unsigned long long fib[25000000];
int c1[10000];
int c2[10000];
main(){
	int n,i,cong,dem;
	long long sum;
	cin>>n;
	sum=0;
	fib[1]=1;
	fib[2]=1;
	i=2;
	for (int i=3;i<=n*n;i++) fib[i]=(fib[i-1]+fib[i-2])%10007;
	if (n%2==0){
		sum-=2;
		c1[1]=1;
		if (n>=1) sum+=c1[1];
		for (int i=2;i<=n;i++){
		 	c1[i]=c1[i-1]+2*(i-1);   // 1 3 7 13 21 31 43 57 73
		 	sum+=fib[c1[i]]%10007;
		}
		c2[1]=2;
		c2[2]=4;
		if (n>=1) sum+=c2[1];
		if (n>=2) sum+=c2[2];
		cong=6;
		dem=0;
		for (int i=3;i<=n;i++){
			c2[i]=c2[i-1]+cong;      // 2 4 10 16 26 36 50 64
			sum+=fib[c2[i]]%10007;
			dem++;
			if (dem==2){
				dem=0;
				cong+=4;
			} 
		}
	}
	else{
		sum-=1;
		c1[1]=1;
		if (n>=1) sum+=c1[1];
		for (int i=2;i<=n;i++){
		 	c1[i]=c1[i-1]+2*(i-1);   // 1 3 7 13 21 31 43 57 73
			sum+=fib[c1[i]]%10007;
		}
		c2[1]=1;
		if (n>=1) sum+=c2[1];
		cong=4;
		dem=0;
		for (int i=2;i<=n;i++){
			c2[i]=c2[i-1]+cong;      // 1 5 9 17 25 37 49 65 81
			sum+=fib[c2[i]]%10007;
			dem++;
			if (dem==2){
				dem=0;
				cong+=4;
			} 
		}
	}
	cout<<sum%10007;
}
