#include <iostream>
#include <string.h>
using namespace std;
string a,kq,s;
int i,j,lmax=0;
int b[50000];
int main()
{
    cin>>a;
    for (i=0;i<a.size();i++)
    {
    	s="";
        int d=0;
        memset(b,0,sizeof(b));
        for (j=i;j<a.size();j++)
        if (b[a[j]]==0)
        {
        	s+=a[j];
            d++;
            b[a[j]]++;
        }
        else break;
        if (d>lmax){
        	lmax=d;
        	kq=s;
		}
    }
    cout<<kq;
}
    
