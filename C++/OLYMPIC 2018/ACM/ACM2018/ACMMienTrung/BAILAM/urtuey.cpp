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
    	int dd=(int)a[i];
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
        if (d>=lmax && (int)s[0]>(int)kq[0]){
        	COUT<<KQ<<ENDL;
        	lmax=d;
        	kq=s;
		}
    }
    cout<<kq;
}
    
