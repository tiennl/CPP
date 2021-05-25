#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i =1; i<=n;i++)
		{
			for( j=1;j<=i;j++)
			{
				cout<<" * ";
			}
			cout<<endl;
		}
		for( i=n-1;i>=1;i--)
		{
			for(j=1;j<=i;j++)
			{
				cout<<" * ";
			}
			cout<<endl;
		}
	}
}

