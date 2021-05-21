#include<iostream>
using namespace std;
long long re=0;
long long kq=0;
int m;
int dem(int n)
{
    int de=0;
    while(n>0)
    {
        de++;
        n/=10;
    }
    return de;
}
bool result(int n,int point,int multi)
{
    int d=dem(n);
    int check=1;
    for(int i=1;i<d;i++)check*=10;
    while(d>0)
    {
        if(dem(re)==point)
        {
            re=re%multi;
            re=re*10+n/check;
        }
        else re=re*10+n/check;
        kq++;
        if(re==m)return true;
        n%=check;
        check/=10;
        d--;
    }
    return false;
}
main()
{

    cin>>m;
    int point=dem(m);
    int multi=1;
    for(int i=1;i<point;i++)multi*=10;
    for(int i=1;i<=m;i++)
    {
        if(result(i,point,multi))
        {
            cout<<kq-point+1;
            break;
        }
    }
}
