#include<iostream>
using namespace std;
string arraystr[]={"ABSINTH", "TEQUILA", "VODKA", "WHISKEY" , "WINE", "BEER", "BRANDY" , "CHAMPAGNE", "GIN", "RUM", "SAKE"};
bool isAncol(string s)
{
    for(int i=0;i<11;i++)
    {
        if(s==arraystr[i])return true;
    }
    return false;
}
long long oldPerson(string s)
{
    long long old=0;
    while(s.size()>0)
    {
        old=old*10+(int)(s[0]-48);
        s.erase(0,1);
    }
    return old;
}
main()
{
    int n, result=0;
    string st;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>st;
        if(st[0]>47&&st[0]<58)
        {
            if(oldPerson(st)<18)result++;
        }
        else
        {
            if(isAncol(st))result++;
        }
    }
    cout<<result;
}
