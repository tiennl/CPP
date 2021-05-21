#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define base 1000000007
struct MaTran
{
    long long c[2][2];
     MaTran()
    {
        c[0][0]=0;
        c[0][1]=1;
        c[1][0]=1;
        c[1][1]=1;
    }
};
 
MaTran operator * (MaTran a, MaTran b)
{
    MaTran res;
    for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++)
        {
            res.c[i][j] = 0;
            for (int k=0; k<=1; k++)
                res.c[i][j] = (res.c[i][j]+a.c[i][k]*b.c[k][j])%base;
        }
    return res;
}
 
MaTran powermod (MaTran a, long long n)
{
    if (n==1)
        return a;
    if (n%2!=0)
        return powermod(a,n-1)*a;
    MaTran tmp = powermod(a,n/2);
    return tmp*tmp;
}
  
ll Fibo(ll n){
	MaTran A;
	A=powermod(A,n);
	return A.c[0][1];
}

int main(){
	FIO
	ll a1,n,s=0;
	cin>>a1>>n;
	s=Fibo(n+2)-1;
	s%=base;
	s=s*a1%base;
	cout<<s;
	return 0;
}
