#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	string s,ss,kq;
	getline(cin,s);
	ss="";
	int i,j,max,hieu,kt;
	max=0;
	int t=0;
	for(i=1;i<s.length();i++)
	{
		max=1;
		ss=s[i];
		for(j=t;j<i;j++)
		{			
			if(s[i]!=s[j]){
				max++;
				ss+=s[j];
			}
			else t=j+1;	
		}
		if(max>hieu){
			hieu=max;
			kq=ss;
		}
	}		
	cout<<kq;
	
}
    
