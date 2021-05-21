#include<iostream>
#include<vector>
using namespace std;
vector<int> vectornum;
long long arraynk[57][57];
long long n,k,x;
void values(int n)
{
    for(int i=0;i<=n;i++)arraynk[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            arraynk[i][j]=arraynk[i-1][j]+arraynk[i-1][j-1];
        }
    }
}
void result(int index)
{
    for(int i=index;i<=n;i++)
    {
        if(arraynk[n-i][k-vectornum.size()]>x)
        {
            vectornum.push_back(i);
        }
        else
        {
            x-=arraynk[n-i][k-vectornum.size()];
        }
    }
}
main()
{

    cin>>n>>k>>x;
    values(n);
    vectornum.push_back(1);
    result(vectornum[vectornum.size()-1]);
    for(int i=1;i<vectornum.size();i++)cout<<vectornum[i]<<" ";
}
