#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<string> vectorstr;
set<char> setchar[26];
set<int>setres;
void check(string a,string b)
{
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        if(a[i]!=b[i])
        {
            setchar[b[i]-97].insert(a[i]);
            break;
        }
    }
}
main()
{
    char c;int n;string st;
   cin>>c>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>st;
       vectorstr.push_back(st);
   }
   for(int i=0;i<n-1;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           check(vectorstr[i],vectorstr[j]);
       }
   }
   bool check1=true;
   while(check1)
   {
        check1=false;;
        for(int i=0;i<=c-97;i++)
        {
            int lenght=setchar[i].size();
            for(set<char> ::iterator j=setchar[i].begin();j!=setchar[i].end();j++)
            {
                for(set<char>::iterator t=setchar[*j-97].begin();t!=setchar[*j-97].end();t++)setchar[i].insert(*t);
            }
            if(lenght!=setchar[i].size())check1=true;
        }
   }
   for(int i=0;i<=c-97;i++)
   {
       setres.insert(setchar[i].size());
   }
  /* for(int i=0;i<=c-97;i++)
   {
       cout<<(char)(i+97)<<"  :  ";
       for(set<char>::iterator j=setchar[i].begin();j!=setchar[i].end();j++)
       {
           cout<<*j<<" ";
       }
       cout<<endl;
   }*/
   if(setres.size()==c-96)
   {
       for(int i=0;i<=c-97;i++)
       {
           for(int j=0;j<=c-97;j++)
           {
               if(i==setchar[j].size())
               {
                   cout<<char(j+97);
                   break;
               }
           }
       }
   }
   else
   {
       bool result=true;
       for(int i=0;i<=c-97;i++)
       {
           for(set<char>::iterator j=setchar[i].begin();j!=setchar[i].end();j++)
           {
               if(*j==i+97)
               {
                   cout<<"IMPOSSIBLE";
                   result=false;
                   break;
               }
           }
           if(result==false)break;
       }
       if(result)
       {
            for(int i=0;i<=c-97;i++)
            {
                int dem=0;
                for(int t=0;t<=c-97;t++)
                {
                    if(t!=i)
                    for(set<char>::iterator j=setchar[t].begin();j!=setchar[t].end();j++)
                    {
                        if(*j==(char)i+97)
                        {
                            dem++;
                            break;
                        }
                    }
                }
                if(dem>c-97-setchar[i].size())
                {
                    cout<<"IMPOSSIBLE";
                    result=false;
                    break;
                }
           }
           if(result)
           {
               cout<<"AMBIGUOUS";
           }
       }
   }
}
