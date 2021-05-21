#include<iostream>
#include<map>
using namespace std;
map<pair<int,int>,bool> mapnum;
long long red[100007],blue[100007]={0};
main()
{
    long long n,m;
    int x,y;
    cin>>n>>m;
    pair<int,int> pairnum;
    for(int i=1;i<=n;i++)red[i]=n-1;
    long long result=(n*(n-1)*(n-2))/6,unresult=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(x>y)swap(x,y);
        pairnum=pair<int,int> (x,y);
        unresult-=(red[x]*blue[x]+red[y]*blue[y]);
        if(mapnum.find(pairnum)!=mapnum.end())
        {
            if(mapnum.find(pairnum)->second==true)
            {
                red[x]++;
                blue[x]--;
                red[y]++;
                blue[y]--;
                mapnum.find(pairnum)->second=false;
            }
            else
            {

                red[x]--;
                blue[x]++;
                red[y]--;
                blue[y]++;
                mapnum.find(pairnum)->second=true;
            }
        }
        else
        {
            mapnum.insert(pair<pair<int,int>,bool>(pairnum,true));
            red[x]--;
            blue[x]++;
            red[y]--;
            blue[y]++;
        }
        unresult+=(red[x]*blue[x]+red[y]*blue[y]);
        cout<<result-unresult/2<<endl;
    }
}
