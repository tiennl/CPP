#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    long long a[n+10],dem=n,dau=0,duoi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];



    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[duoi])
            {
                duoi=i;
                dem+=(duoi-dau);


            }
        else
        {

            dau=i;
            duoi=i;

        }

    }
    dau=n-1;duoi=n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[duoi])
            {
                duoi=i;
                dem+=(dau-duoi);


            }
        else
        {
            dau=i;
            duoi=i;

        }
    }
    cout<<dem;

    return 0;
}

