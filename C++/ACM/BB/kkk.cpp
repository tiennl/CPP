#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        int n;
    cin>>n;

    long long a[n+10],mi=0,ma=0,dem=n,dema=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];



    }
    for(int i=1;i<n;i++)
    {
    	
        if(a[i]>a[ma])
            {
                ma=i;
                dem+=(ma-mi-dema);


            }
        else
        {
            dema++;


        }
        if(a[i]<a[mi])
            {
                mi=i;
                ma=i;
                dema=0;
            }

    }
    mi=n-1;ma=n-1;
    dema=0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[ma])
            {
                ma=i;
                dem+=(mi-ma-dema);


            }
        else
        {
            dema++;


        }
        if(a[i]<a[mi])
            {
                mi=i;
                ma=i;
                dema=0;
            }

    }

    cout<<dem;

    return 0;
}


