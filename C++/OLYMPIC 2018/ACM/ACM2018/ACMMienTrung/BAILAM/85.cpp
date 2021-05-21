#include <bits/stdc++.h>
#define FOR(i,a,b)  for(int i=a;i<=b;i++)
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a[30];
    int n=s.length()-1;
    int mark=0;
    int count=0;
    int res=LONG_MIN;
    FOR(i,1,n)
    {
        count=1;
        FOR(j,mark,i-1)
        if (s[i]!=s[j]) count++;// cout<<i<<" "<<j<<count<<endl;}
        else mark=j+1;

        res=max(res,count);
    }
    cout<<res;

}
    
