#include<bits/stdc++.h>
int main ()
{
	char str[500];
	char string[256]={0};
	gets(str);
	int n=strlen(str),c=0;
	for(int i=0;i<n;i++)
	{
		str[i]=tolower(str[i]);
		if(isalpha(str[i])!=false)
		{
			string[str[i]]++;
		}
	}
	for(int i=0;i<256;i++)
	{
		if(string[i]>0)
		{
			c++;		
		}
	}
	printf("%d",c);
	return 0;
}
