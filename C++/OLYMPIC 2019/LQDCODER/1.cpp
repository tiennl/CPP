	
#include<stdio.h>
#define MAX   200000
#define MOD   111539786
typedef unsigned long long ull;
ull n;
ull fib[MAX+2];
int t,ct;
void init(void)
{
     ull i;
     fib[1]=1;
     fib[2]=1;
     for (i=3;i<MAX;i=i+1) fib[i]=(fib[i-1]+fib[i-2])%MOD;
}
ull fibo(ull n)
{
    if (n<MAX) return (fib[n]);
    if (n%2==1)
       {
        ull k=(n+1)/2;
        ull f1=fibo(k);
        ull f2=fibo(k-1);
        return ((f1*f1+f2*f2)%MOD);
       }
    if (n%2==0)
       {
        ull k=n/2;
        ull f1=fibo(k);
        ull f2=fibo(k-1);
        return ((f1*f1+2*f1*f2)%MOD);
       }
}
int main(void)
{
    init();
    scanf("%d",&t);
    for (ct=1;ct<=t;ct=ct+1)
        {
         scanf("%llu",&n);
         printf("%llu\n",fibo(n+1));
        }
}
 
