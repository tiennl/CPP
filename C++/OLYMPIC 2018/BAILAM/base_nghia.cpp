#include<iostream>
#include<math.h>
using namespace std;

bool check(long long n,int i,int temp)
{
    while(n>0)
    {
        if(n%i!=temp)return false;
        n=n/i;
    }
    return true;
}
main()
{
    long long n;
    cin>>n;
    long long re=-1;
    for(int i=2;i<=sqrt(n);i++)
    {
        int temp=n%i;
        if(check(n,i,temp))
        {
            re=i;
            break;
        }
    }
    if(re==-1)
    {
        for(int i=sqrt(n);i>=1;i--)
        {
            if((n-i)%i==0&& n-i!=i*i)
            {
                re=(n-i)/i;
                break;
            }
        }
    }
    if(re<1)re=n+1;
    cout<<re;
}
