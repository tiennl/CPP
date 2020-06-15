#include <iostream>
#include <math.h>
using namespace std;
#define k 1000000007
int main(){
    float a,b;
    unsigned long long n,m;
    unsigned long long sum = 0;
    cin>>a>>b;
    if (int(a)==a) n=(int)a;
	else n=(int)a+1; 
    m=(int)b;
    for (long long i=n;i<=m;i++) sum=(sum+i*i)%k;
    cout<<sum;
    return 0;
}
// 0 10000     -> 383332669
// 0 100000    -> 331016634
// 0 1000000   -> 163183
// 0 10000000  -> 1333000
// 0 100000000 -> 998000007
