#include<iostream>
#include<vector>
using namespace std;
vector<long long> vectornumber;
long long sumcheck=0;
long long ucln(long long a,long long b)
{
    if(a>b)
    {
        a=a%b;
        if(a==0)return b;
        else return ucln(a,b);
    }
    else
    {
        b=b%a;
        if(b==0)return a;
        else return ucln(a,b);
    }
}
void sumcheck1(long long k,int t,int index,long long oldnumber)
{
    for(int i=index;i<vectornumber.size();i++)
    {

        long long tempuc=ucln(vectornumber[i],oldnumber);
        if((vectornumber[i]*oldnumber)/tempuc<=k)
        {
            if(t%2==1)sumcheck+=k/((vectornumber[i]*oldnumber)/tempuc);
            else
            {
                sumcheck-=k/((vectornumber[i]*oldnumber)/tempuc);
            }
        }
        sumcheck1(k,t+1,i+1,(vectornumber[i]*oldnumber)/tempuc);
    }
}
main()
{
    long long test,n,k,number;
    cin>>test;
    while(test>0)
    {
        test--;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>number;
            vectornumber.push_back(number);
        }
        sumcheck=0;
        long long temp=0;
        long long num=k;
        while(temp<k)
        {
            sumcheck=0;
            sumcheck1(num,1,0,1);
            temp=num-sumcheck;
            if(temp<k)num+=k-temp;
        }
        for(int i=num;i>=0;i--)
        {
            bool kt=1;
            for(int j=0;j<vectornumber.size();j++)
            {
                if(i%vectornumber[j]==0)
                {
                    kt=0;
                    break;
                }
            }
            if(kt)
            {

                if(temp==k)
                {
                    cout<<i<<endl;
                    break;
                }
                temp--;
            }
        }
        vectornumber.clear();
    }
}
