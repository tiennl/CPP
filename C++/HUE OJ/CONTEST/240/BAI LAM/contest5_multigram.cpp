#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string multigram;
main()
{
    int i, n=0, a=0;
    cin>>multigram;
    for(i=0;i<multigram.size();i++)
        if(multigram[i]!=multigram[0])
        a++;
    if(a==0)
    {
        cout<<multigram[0]<<endl;
        return 0;
    }
    sort(multigram.begin(), multigram.end());
    for(i=0;i<multigram.size();i++)
    {
        if(multigram[i]!=multigram[i+1])
            n=1;
    }
    if(n!=0)
        cout<<"-1";
    else
    {
        for(i=0;i<(multigram.size())/2;i++)
            cout<<multigram[i];
    }
    cout<<endl;
}
