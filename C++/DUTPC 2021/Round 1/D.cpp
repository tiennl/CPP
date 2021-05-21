#include<bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

long long n;

int main()
{
   cin>>n;
   char hex[10];
    sprintf(hex,"%08X",n);
    for(int i = 0;i < 4;i++)cout<<hex[i];
    cout<<" ";
    for(int i = 4;i < 8;i++)cout<<hex[i];
    return 0;
}
